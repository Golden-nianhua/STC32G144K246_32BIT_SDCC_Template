#include "bsp_rs485.h"
#include "bsp_board.h"
#include "bsp_config.h"
#include "system_stc32.h"

/* UART4/8 由 Timer4/8 的 1T 溢出时钟四分频，8N1 共 10 位。
 * 90 MHz 下最低可用波特率约 343.3 bit/s；计数四舍五入。 */
#define RS485_BAUD_MIN          344UL
#define RS485_BAUD_MAX          3000000UL

static uint32_t rs485_uart4_baud;
static uint32_t rs485_uart8_baud;

static uint8_t uart4_dma_active(void)
{
    return (DMA_UR4T_CR & (DMAUR4TCR_ENUR4T_MSK | DMAUR4TCR_TRIG_MSK)) ||
           (DMA_UR4R_CR & (DMAUR4RCR_ENUR4R_MSK | DMAUR4RCR_TRIG_MSK));
}

static uint8_t uart8_dma_active(void)
{
    return (DMA_UR8T_CR & (DMAUR8TCR_ENUR8T_MSK | DMAUR8TCR_TRIG_MSK)) ||
           (DMA_UR8R_CR & (DMAUR8RCR_ENUR8R_MSK | DMAUR8RCR_TRIG_MSK));
}

static uint32_t baud_counts(uint32_t baud)
{
    return (SYSCLK + 2UL * baud) / (4UL * baud);
}

static uint8_t baud_error_ok(uint32_t baud, uint32_t counts)
{
    uint32_t actual;
    uint32_t error;
    if (counts == 0UL || counts > 65535UL) return 0;
    actual = SYSCLK / (4UL * counts);
    error = actual > baud ? actual - baud : baud - actual;
    /* UART 一般要求总误差 <3%；按四舍五入后仍不差于目标/33 保守校验。 */
    return error <= baud / 33UL;
}

/* 只在本模块 init 与 write 中操作 DIR，均使用位写寄存器。
 * 用编译期分支生成宏，避免常量条件造成不可达代码警告。 */
#if BSP_RS485_TX_HIGH
#define UART4_DIR_TX() (PASETB = PIN_4)
#define UART4_DIR_RX() (PACLRB = PIN_4)
#define UART8_DIR_TX() (PASETB = PIN_5)
#define UART8_DIR_RX() (PACLRB = PIN_5)
#else
#define UART4_DIR_TX() (PACLRB = PIN_4)
#define UART4_DIR_RX() (PASETB = PIN_4)
#define UART8_DIR_TX() (PACLRB = PIN_5)
#define UART8_DIR_RX() (PASETB = PIN_5)
#endif

/* S4TI/S8TI 在停止位开始时置位，此时停止位仍在移位。
 * 至少等待 ceil(1 bit 的毫秒数)+1 ms；+1 ms 用于覆盖 system_millis()
 * 正好在 tick 边界取样时只差几微秒的情况。返回 0 表示总预算已用尽。 */
static uint8_t rs485_wait_last_bit(uint32_t baud, uint32_t start,
                                   uint32_t timeout_ms)
{
    uint32_t guard_ms;
    uint32_t tx_done;
    uint32_t now;
    if (baud == 0UL) return 1U;
    guard_ms = (1000UL + baud - 1UL) / baud + 1UL;
    tx_done = system_millis();
    for (;;) {
        now = system_millis();
        if ((uint32_t)(now - start) >= timeout_ms) return 0U;
        if ((uint32_t)(now - tx_done) >= guard_ms) return 1U;
    }
}

/* 首字节不能等待上一帧的 TI：初始化后 TI 可能为 0，直接等待会空转到超时。
 * 第 i>0 字节先等前一字节的 TI，再清 TI 并写入当前字节。 */
static bsp_status_t rs485_uart4_write_bytes(const uint8_t *data, uint16_t len,
                                            uint32_t timeout_ms)
{
    uint32_t start = system_millis();
    uint16_t i;
    UART4_ClearTxFlag();
    UART4_SendData(data[0]);
    for (i = 1U; i < len; ++i) {
        while (!UART4_CheckTxFlag()) {
            if ((uint32_t)(system_millis() - start) >= timeout_ms)
                return BSP_ERROR_TIMEOUT;
        }
        UART4_ClearTxFlag();
        UART4_SendData(data[i]);
    }
    /* 等最后一个字节到达停止位起点，随后保护等待完整末位。 */
    if (!UART4_CheckTxFlag()) {
        while (!UART4_CheckTxFlag()) {
            if ((uint32_t)(system_millis() - start) >= timeout_ms)
                return BSP_ERROR_TIMEOUT;
        }
    }
    UART4_ClearTxFlag();
    if (!rs485_wait_last_bit(rs485_uart4_baud, start, timeout_ms))
        return BSP_ERROR_TIMEOUT;
    return BSP_OK;
}

static bsp_status_t rs485_uart8_write_bytes(const uint8_t *data, uint16_t len,
                                            uint32_t timeout_ms)
{
    uint32_t start = system_millis();
    uint16_t i;
    UART8_ClearTxFlag();
    UART8_SendData(data[0]);
    for (i = 1U; i < len; ++i) {
        while (!UART8_CheckTxFlag()) {
            if ((uint32_t)(system_millis() - start) >= timeout_ms)
                return BSP_ERROR_TIMEOUT;
        }
        UART8_ClearTxFlag();
        UART8_SendData(data[i]);
    }
    /* 等最后一个字节到达停止位起点，随后保护等待完整末位。 */
    if (!UART8_CheckTxFlag()) {
        while (!UART8_CheckTxFlag()) {
            if ((uint32_t)(system_millis() - start) >= timeout_ms)
                return BSP_ERROR_TIMEOUT;
        }
    }
    UART8_ClearTxFlag();
    if (!rs485_wait_last_bit(rs485_uart8_baud, start, timeout_ms))
        return BSP_ERROR_TIMEOUT;
    return BSP_OK;
}

bsp_status_t bsp_rs485_uart4_init(uint32_t baud)
{
    uint32_t counts;
    if (!bsp_timebase_ready()) return BSP_ERROR_NOT_READY;
    if (baud < RS485_BAUD_MIN || baud > RS485_BAUD_MAX)
        return BSP_ERROR_ARGUMENT;
    counts = baud_counts(baud);
    if (!baud_error_ok(baud, counts)) return BSP_ERROR_ARGUMENT;
    if (uart4_dma_active()) return BSP_ERROR_BUSY;
    if (bsp_board_prepare(BSP_RESOURCE_RS485_UART4) != BSP_OK)
        return BSP_ERROR_NOT_READY;

    UART4_DIR_RX();
    UART4_DisableInt();       /* 轮询模式，不占用 UART4 中断向量。 */
    UART4_DisableTimeout();
    UART4_DisableTimeoutInt();
    UART4_NoneParity();
    S4CON = 0x50U;            /* 模式 1：8 位数据，允许接收。 */
    S4CFG &= (uint8_t)~0xe1U; /* 不倍速、无 FE、Timer4 作为 BRT。 */
    UART4_Timer4BRT();

    TIMER4_Stop();
    TIMER4_DisableInt();
    TIMER4_TimerMode();
    TIMER4_1TMode();
    TIMER4_DisableCLKO();
    TIMER4_SetPrescale(0);
    TIMER4_SetReload16((uint16_t)(65536UL - counts));
    TIMER4_ClearFlag();
    TIMER4_Run();

    UART4_ClearTxFlag();
    UART4_ClearRxFlag();
    rs485_uart4_baud = SYSCLK / (4UL * counts);
    return BSP_OK;
}

bsp_status_t bsp_rs485_uart8_init(uint32_t baud)
{
    uint32_t counts;
    if (!bsp_timebase_ready()) return BSP_ERROR_NOT_READY;
    if (baud < RS485_BAUD_MIN || baud > RS485_BAUD_MAX)
        return BSP_ERROR_ARGUMENT;
    counts = baud_counts(baud);
    if (!baud_error_ok(baud, counts)) return BSP_ERROR_ARGUMENT;
    if (uart8_dma_active()) return BSP_ERROR_BUSY;
    if (bsp_board_prepare(BSP_RESOURCE_RS485_UART8) != BSP_OK)
        return BSP_ERROR_NOT_READY;

    UART8_DIR_RX();
    UART8_DisableInt();
    UART8_DisableTimeout();
    UART8_DisableTimeoutInt();
    UART8_NoneParity();
    S8CON = 0x50U;
    S8CFG &= (uint8_t)~0xe1U;
    UART8_Timer8BRT();

    TIMER8_Stop();
    TIMER8_DisableInt();
    TIMER8_TimerMode();
    TIMER8_1TMode();
    TIMER8_DisableCLKO();
    TIMER8_SetPrescale(0);
    TIMER8_SetReload16((uint16_t)(65536UL - counts));
    TIMER8_ClearFlag();
    TIMER8_Run();

    UART8_ClearTxFlag();
    UART8_ClearRxFlag();
    rs485_uart8_baud = SYSCLK / (4UL * counts);
    return BSP_OK;
}

bsp_status_t bsp_rs485_uart4_try_read(uint8_t *byte)
{
    if (byte == 0) return BSP_ERROR_ARGUMENT;
    if (rs485_uart4_baud == 0UL) return BSP_ERROR_NOT_READY;
    if (uart4_dma_active()) return BSP_ERROR_BUSY;
    if (!UART4_CheckRxFlag()) return BSP_ERROR_NOT_READY;
    *byte = UART4_ReadData();
    UART4_ClearRxFlag();
    return BSP_OK;
}

bsp_status_t bsp_rs485_uart8_try_read(uint8_t *byte)
{
    if (byte == 0) return BSP_ERROR_ARGUMENT;
    if (rs485_uart8_baud == 0UL) return BSP_ERROR_NOT_READY;
    if (uart8_dma_active()) return BSP_ERROR_BUSY;
    if (!UART8_CheckRxFlag()) return BSP_ERROR_NOT_READY;
    *byte = UART8_ReadData();
    UART8_ClearRxFlag();
    return BSP_OK;
}

bsp_status_t bsp_rs485_uart4_write(const uint8_t *buffer, uint16_t len,
                                   uint32_t timeout_ms)
{
    bsp_status_t status = BSP_OK;
    if (len == 0U) return BSP_OK;
    if (buffer == 0) return BSP_ERROR_ARGUMENT;
    if (rs485_uart4_baud == 0UL) return BSP_ERROR_NOT_READY;
    if (!bsp_timebase_ready()) return BSP_ERROR_NOT_READY;

    if (uart4_dma_active()) return BSP_ERROR_BUSY;
    if (!timeout_ms) return BSP_ERROR_TIMEOUT;
    UART4_DIR_TX();
    status = rs485_uart4_write_bytes(buffer, len, timeout_ms);
    UART4_DIR_RX();
    return status;
}

bsp_status_t bsp_rs485_uart8_write(const uint8_t *buffer, uint16_t len,
                                   uint32_t timeout_ms)
{
    bsp_status_t status = BSP_OK;
    if (len == 0U) return BSP_OK;
    if (buffer == 0) return BSP_ERROR_ARGUMENT;
    if (rs485_uart8_baud == 0UL) return BSP_ERROR_NOT_READY;
    if (!bsp_timebase_ready()) return BSP_ERROR_NOT_READY;

    if (uart8_dma_active()) return BSP_ERROR_BUSY;
    if (!timeout_ms) return BSP_ERROR_TIMEOUT;
    UART8_DIR_TX();
    status = rs485_uart8_write_bytes(buffer, len, timeout_ms);
    UART8_DIR_RX();
    return status;
}
