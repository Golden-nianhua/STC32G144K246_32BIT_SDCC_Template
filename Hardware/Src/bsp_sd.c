#include "bsp_sd.h"
#include "bsp_board.h"
#include "bsp_gpio.h"
#include "system_stc32.h"

#define SD_SPI2_BASE_DIV BSP_SD_DEFAULT_CLKDIV /* 180 MHz / 113 / 4 ≈ 398.2 kHz。 */

/* 0=未初始化，1=硬件 SPI2，2=GPIO Mode0 后备。 */
#define SD_BACKEND_NONE 0U
#define SD_BACKEND_SPI2 1U
#define SD_BACKEND_GPIO 2U

/* SPI2 工作时钟来自 HSIOCLK，而不是 SYSCLK。
 * SCLK2 = HSIOCLK/SPI2_CLKDIV/SP2R；clkdiv 为 0 表示不参与计算。 */
static uint32_t sd_sclk_hz(uint8_t clkdiv, uint8_t spr)
{
    uint32_t post;
    if (clkdiv == 0U) return 0UL;
    if (spr == 0U) post = 4UL;
    else if (spr == 1U) post = 8UL;
    else if (spr == 2U) post = 16UL;
    else post = 2UL;
    return BOARD_HSIO_HZ / ((uint32_t)clkdiv * post);
}

static uint8_t sd_backend;

static uint8_t sd_dma_active(void)
{
    return DMA_SPI2_CR & (DMASPI2CR_ENSPI_MSK | DMASPI2CR_TRIGS_MSK);
}

/* SPI2CTL: SS2IG=1 固定主机，SP2DORD=0 为 MSB，SP2MSTR=1；
 * CPOL=1、CPHA=1 为 Mode3；SP2R 为输入时钟分频。
 * 手册 25.5 明确 CPHA=0 要求 SS2IG=0，而本板 CS 固定由 PB.1 软件驱动；
 * 因此硬件传输使用手册明确支持的软件 CS + Mode3 组合。 */
static void sd_controller_config(uint8_t clkdiv, uint8_t spr)
{
    SPI2_Disable();
    SPI2_DisableInt();
    SPI2_DisableTimeout();
    SPI2_DisableTimeoutInt();
    HSSPI2_Disable();
    HSSPI2_DisableFIFO();
    HSSPI2_CFG2 &= (uint8_t)~HSSPI2CFG2_IOSW_MSK;
    if (spr == 3U) HSSPI2_Enable(); /* 手册要求系统时钟/2 档启用高速模式。 */
    CLK_SPI2CLK_Divider(clkdiv);
    /* SS2IG=1、MSTR=1、MSB、Mode3；SP2R=0 为输入时钟/4。 */
    SPI2CTL = (uint8_t)(SPI2CTL_SSIG_MSK | SPI2CTL_MSTR_MSK |
                        SPI2CTL_CPOL_MSK | SPI2CTL_CPHA_MSK |
                        (spr & SPI2CTL_SPR_MSK));
    SPI2_ClearFlag();
    SPI2_Enable();
}

bsp_status_t bsp_sd_init(uint8_t spi2_clkdiv)
{
    uint32_t sclk;
    if (!bsp_timebase_ready()) return BSP_ERROR_NOT_READY;
    if (spi2_clkdiv == 0U) return BSP_ERROR_ARGUMENT;
    sclk = sd_sclk_hz(spi2_clkdiv, 0U);
    if (sclk == 0UL || sclk > 400000UL) return BSP_ERROR_ARGUMENT;
    if (sd_dma_active()) return BSP_ERROR_BUSY;
    SPI2_Disable();
    if (bsp_board_prepare(BSP_RESOURCE_SPI2_SD) != BSP_OK)
        return BSP_ERROR_NOT_READY;
    bsp_sd_cs_deselect();
    PBSETB = PIN_4; /* Mode3 空闲时钟为高。 */
    sd_controller_config(spi2_clkdiv, 0U);
    sd_backend = SD_BACKEND_SPI2;
    return BSP_OK;
}

bsp_status_t bsp_sd_init_divider(uint8_t divider)
{
    uint8_t spr;
    if (!bsp_timebase_ready()) return BSP_ERROR_NOT_READY;
    switch (divider) {
    case 2U:  spr = 3U; break;
    case 4U:  spr = 0U; break;
    case 8U:  spr = 1U; break;
    case 16U: spr = 2U; break;
    default:  return BSP_ERROR_ARGUMENT;
    }
    if (sd_dma_active()) return BSP_ERROR_BUSY;
    SPI2_Disable();
    if (bsp_board_prepare(BSP_RESOURCE_SPI2_SD) != BSP_OK)
        return BSP_ERROR_NOT_READY;
    bsp_sd_cs_deselect();
    PBSETB = PIN_4;
    sd_controller_config(SD_SPI2_BASE_DIV, spr);
    sd_backend = SD_BACKEND_SPI2;
    return BSP_OK;
}

/* GPIO Mode0 的半周期延时。使用工程可移植 NOP 宏，宿主编译时展开为空操作；
 * SYSCLK=90 MHz 下粗略低于 400 kHz，仅用于不支持 Mode3 的 SD 卡低速后备。 */
static void sd_gpio_half_delay(void)
{
    volatile uint8_t i;
    for (i = 0U; i < 10U; ++i) {
        NOP(10);
    }
}

bsp_status_t bsp_sd_init_gpio_mode0(void)
{
    if (!bsp_timebase_ready()) return BSP_ERROR_NOT_READY;
    if (sd_dma_active()) return BSP_ERROR_BUSY;
    SPI2_Disable();
    if (bsp_board_prepare(BSP_RESOURCE_SPI2_SD) != BSP_OK)
        return BSP_ERROR_NOT_READY;
    SPI2_Disable();          /* 关闭硬件 SPI2，PB 引脚按 GPIO 使用。 */
    HSSPI2_Disable();
    HSSPI2_DisableFIFO();
    HSSPI2_CFG2 &= (uint8_t)~HSSPI2CFG2_IOSW_MSK; /* 清除 MOSI/MISO 交换。 */
    PBCLRB = PIN_4;          /* Mode0：CLK 空闲低。 */
    PBSETB = PIN_2;          /* MOSI 空闲高。 */
    bsp_sd_cs_deselect();
    sd_backend = SD_BACKEND_GPIO;
    return BSP_OK;
}

static bsp_status_t sd_gpio_transfer(const uint8_t *tx, uint8_t *rx,
                                     uint16_t count, uint32_t timeout_ms)
{
    uint32_t start = system_millis();
    uint16_t i;
    uint8_t bit;
    uint8_t out;
    uint8_t in;
    for (i = 0U; i < count; ++i) {
        if ((uint32_t)(system_millis() - start) >= timeout_ms)
            return BSP_ERROR_TIMEOUT;
        out = (tx != 0) ? tx[i] : 0xffU;
        in = 0U;
        for (bit = 0x80U; bit != 0U; bit >>= 1) {
            if (out & bit) PBSETB = PIN_2;
            else PBCLRB = PIN_2;
            sd_gpio_half_delay();
            PBSETB = PIN_4;  /* Mode0 上升沿采样。 */
            sd_gpio_half_delay();
            in = (uint8_t)((in << 1) | ((PBIN & PIN_3) ? 1U : 0U));
            PBCLRB = PIN_4;
            sd_gpio_half_delay();
        }
        if (rx != 0) rx[i] = in;
    }
    return BSP_OK;
}

void bsp_sd_cs_select(void)
{
    PBCLRB = PIN_1;
}

void bsp_sd_cs_deselect(void)
{
    PBSETB = PIN_1;
}

bsp_status_t bsp_sd_transfer(const uint8_t *tx, uint8_t *rx, uint16_t count,
                             uint32_t timeout_ms)
{
    uint32_t start;
    uint16_t i;
    uint8_t byte;
    if (count == 0U) return BSP_OK;
    if (sd_backend == SD_BACKEND_NONE) return BSP_ERROR_NOT_READY;
    if (!bsp_timebase_ready()) return BSP_ERROR_NOT_READY;
    if (sd_dma_active()) return BSP_ERROR_BUSY;
    if (!timeout_ms) return BSP_ERROR_TIMEOUT;
    if (sd_backend == SD_BACKEND_GPIO)
        return sd_gpio_transfer(tx, rx, count, timeout_ms);

    start = system_millis();
    for (i = 0U; i < count; ++i) {
        if ((uint32_t)(system_millis() - start) >= timeout_ms) goto failed;
        byte = (tx != 0) ? tx[i] : 0xffU;
        SPI2_ClearFlag();
        SPI2_SendData(byte);
        while (!SPI2_CheckFlag()) {
            if ((uint32_t)(system_millis() - start) >= timeout_ms) {
                goto failed;
            }
        }
        byte = SPI2_ReadData();
        SPI2_ClearFlag();
        if (rx != 0) rx[i] = byte;
    }
    return BSP_OK;
failed:
    /* 清标志不能证明移位器已停止。失败后关闭控制器、释放片选，须重新init。 */
    SPI2_Disable();
    SPI2_ClearFlag();
    bsp_sd_cs_deselect();
    sd_backend = SD_BACKEND_NONE;
    return BSP_ERROR_TIMEOUT;
}
