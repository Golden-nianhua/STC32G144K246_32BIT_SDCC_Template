#include "bsp_i2c.h"
#include "bsp_board.h"
#include "system_stc32.h"

/* 手册 27.1.4：SCL = SYSCLK/(4*speed+8)，speed 为 14 位。
 * 向上取分频，保证SCL不超过请求值；I2CMSACKI=0为ACK，1为NACK。 */
#define I2C_SPEED_MAX 0x3fffUL

static uint8_t i2c_ready;

static uint8_t i2c_command_done(uint32_t start, uint32_t timeout_ms)
{
    while (!I2C1_CheckMasterFlag()) {
        if ((uint32_t)(system_millis() - start) >= timeout_ms) return 0U;
    }
    I2C1_ClearMasterFlag();
    return 1U;
}

static uint8_t i2c_dma_active(void)
{
    return (uint8_t)((DMA_I2C_CR & DMAI2CCR_DMAEN_MSK) ||
                     (DMA_I2CT_CR & DMAI2CTCR_ENI2CT_MSK) ||
                     (DMA_I2CR_CR & DMAI2CRCR_ENI2CR_MSK));
}

/* NACK后的STOP也计入整笔预算。超时后禁用控制器并标记未就绪，
 * 不声称物理总线已释放，也不额外追加一个新的等待预算。 */
static bsp_status_t i2c_recover(bsp_status_t status, uint32_t start, uint32_t timeout_ms)
{
    I2C1_ClearMasterFlag();
    if (status != BSP_ERROR_TIMEOUT &&
        (uint32_t)(system_millis() - start) < timeout_ms) {
        I2C1_Stop();
        if (i2c_command_done(start, timeout_ms) && !I2C1_CheckMasterBusy())
            return status;
    }
    I2C1_Disable();
    I2C1_Idle();
    i2c_ready = 0U;
    return BSP_ERROR_TIMEOUT;
}

static bsp_status_t i2c_send_byte(uint8_t value, uint32_t start,
                                  uint32_t timeout_ms)
{
    bsp_status_t status;
    I2C1_WriteData(value);
    I2C1_SendDataRecvACK();
    if (!i2c_command_done(start, timeout_ms)) return BSP_ERROR_TIMEOUT;
    status = I2C1_MasterReadACK() ? BSP_ERROR_NACK : BSP_OK;
    return status;
}

static bsp_status_t i2c_start(uint32_t start, uint32_t timeout_ms)
{
    I2C1_Start();
    if (!i2c_command_done(start, timeout_ms)) return BSP_ERROR_TIMEOUT;
    return BSP_OK;
}

static bsp_status_t i2c_stop(uint32_t start, uint32_t timeout_ms)
{
    I2C1_Stop();
    if (!i2c_command_done(start, timeout_ms)) return BSP_ERROR_TIMEOUT;
    return BSP_OK;
}

/* 从START到STOP的公共事务；超时会标记未就绪，须显式处理故障再init。 */
static bsp_status_t i2c_transaction(uint8_t address,
                                    const uint8_t *write_data, uint16_t write_len,
                                    uint8_t *read_data, uint16_t read_len,
                                    uint32_t timeout_ms)
{
    bsp_status_t status;
    uint32_t start;
    uint16_t i;

    if (!i2c_ready) return BSP_ERROR_NOT_READY;
    if (address > 0x7fU) return BSP_ERROR_ARGUMENT;
    if (write_len != 0U && write_data == 0) return BSP_ERROR_ARGUMENT;
    if (read_len != 0U && read_data == 0) return BSP_ERROR_ARGUMENT;
    if (!bsp_timebase_ready()) return BSP_ERROR_NOT_READY;
    if (I2C1_CheckMasterBusy() || i2c_dma_active())
        return BSP_ERROR_BUSY;
    if (!timeout_ms) return BSP_ERROR_TIMEOUT;

    start = system_millis();
    status = i2c_start(start, timeout_ms);
    if (status != BSP_OK) {
        return i2c_recover(status, start, timeout_ms);
    }

    /* 纯读先发 R 地址；写后读和探测先发 W 地址。 */
    status = i2c_send_byte((uint8_t)((address << 1) |
                                     ((write_len == 0U && read_len != 0U) ? 1U : 0U)),
                           start, timeout_ms);
    if (status != BSP_OK) {
        return i2c_recover(status, start, timeout_ms);
    }
    if (write_len != 0U) {
        for (i = 0U; i < write_len; ++i) {
            status = i2c_send_byte(write_data[i], start, timeout_ms);
            if (status != BSP_OK) {
                return i2c_recover(status, start, timeout_ms);
            }
        }
    }

    if (read_len != 0U) {
        if (write_len != 0U) {
            /* 写后读才需要重复 START；纯读已在上面发送 R 地址。 */
            status = i2c_start(start, timeout_ms);
            if (status != BSP_OK) {
                return i2c_recover(status, start, timeout_ms);
            }
            status = i2c_send_byte((uint8_t)((address << 1) | 1U),
                                   start, timeout_ms);
            if (status != BSP_OK) {
                return i2c_recover(status, start, timeout_ms);
            }
        }
        for (i = 0U; i < read_len; ++i) {
            if (i + 1U == read_len) I2C1_RecvDataSendNAK();
            else I2C1_RecvDataSendACK();
            if (!i2c_command_done(start, timeout_ms)) {
                return i2c_recover(BSP_ERROR_TIMEOUT, start, timeout_ms);
            }
            read_data[i] = I2C1_ReadData();
        }
    }

    status = i2c_stop(start, timeout_ms);
    if (status != BSP_OK) {
        return i2c_recover(status, start, timeout_ms);
    }
    return BSP_OK;
}

bsp_status_t bsp_i2c_init(uint32_t bus_hz)
{
    uint32_t speed;
    uint32_t denominator;
    if (!bsp_timebase_ready()) return BSP_ERROR_NOT_READY;
    if (bus_hz == 0UL || bus_hz > 1000000UL) return BSP_ERROR_ARGUMENT;
    /* SCL=SYSCLK/(4*speed+8)，speed=(SYSCLK/bus_hz-8)/4；
     * 90 MHz、100 kHz 时 speed=223，实际约 100.0 kHz。 */
    denominator = (SYSCLK + bus_hz - 1UL) / bus_hz;
    speed = denominator <= 8UL ? 0UL : (denominator - 8UL + 3UL) / 4UL;
    if (speed > I2C_SPEED_MAX) return BSP_ERROR_ARGUMENT;
    if (I2C1_CheckMasterBusy() || i2c_dma_active()) return BSP_ERROR_BUSY;
    I2C1_Disable();
    if (bsp_board_prepare(BSP_RESOURCE_I2C1) != BSP_OK)
        return BSP_ERROR_NOT_READY;

    I2C1_DisableMasterInt();
    I2CMSAUX = 0U; /* 禁止写TXD自动触发1010；显式组合命令仍有效，见27.1.6。 */
    I2C1_SetClockDivider((uint16_t)speed);
    I2C1_MasterMode();
    I2C1_ClearMasterFlag();
    I2C1_Idle();
    I2C1_Enable();
    i2c_ready = 1U;
    return BSP_OK;
}

bsp_status_t bsp_i2c_write(uint8_t address, const uint8_t *data, uint16_t len,
                           uint32_t timeout_ms)
{
    return i2c_transaction(address, data, len, 0, 0U, timeout_ms);
}

bsp_status_t bsp_i2c_write_read(uint8_t address,
                                const uint8_t *write_data, uint16_t write_len,
                                uint8_t *read_data, uint16_t read_len,
                                uint32_t timeout_ms)
{
    if (read_len == 0U) return BSP_ERROR_ARGUMENT;
    return i2c_transaction(address, write_data, write_len,
                           read_data, read_len, timeout_ms);
}

bsp_status_t bsp_i2c_probe(uint8_t address, uint32_t timeout_ms)
{
    return i2c_transaction(address, 0, 0U, 0, 0U, timeout_ms);
}
