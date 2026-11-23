#include "bsp_lcd.h"
#include "bsp_board.h"
#include "bsp_config.h"
#include "system_stc32.h"

#if BSP_LCD_SETUP > 7 || BSP_LCD_HOLD > 3 || BSP_LCD_PRESCALER > 255
#error "LCD 时序字段超出硬件范围"
#endif

static uint8_t lcd_ready;
static uint8_t ctp_ready;

bsp_status_t bsp_lcd_bus_init(void)
{
    if (!bsp_timebase_ready()) return BSP_ERROR_NOT_READY;
    if (DMA_LCM_CR & 0x80U) return BSP_ERROR_BUSY;
    LCM_Disable();
    (void)bsp_board_prepare(BSP_RESOURCE_LCD8080);
    LCM_DisableInt();
    LCM_SetBitWidth_8B();
    LCM_SetMode_i8080();
    LCM_SetClockDivider(BSP_LCD_PRESCALER);
    LCM_SetSetupTime(BSP_LCD_SETUP);
    LCM_SetHoldTime(BSP_LCD_HOLD);
    LCM_SetDataBigEndian();
    LCM_Idle();
    LCM_ClearFlag();
    LCM_Enable();
    lcd_ready = 1;
    return BSP_OK;
}

static bsp_status_t lcd_wait(uint32_t start_ms, uint32_t timeout_ms)
{
    while (!LCM_CheckFlag()) {
        if ((uint32_t)(system_millis() - start_ms) >= timeout_ms) {
            LCM_Disable();
            PBSETB = PIN_0;
            lcd_ready = 0; /* 不继续使用状态不明的控制器，显式重新 init 后恢复。 */
            return BSP_ERROR_TIMEOUT;
        }
    }
    LCM_ClearFlag();
    return BSP_OK;
}

static bsp_status_t lcd_transfer(uint8_t command, const uint8_t *tx, uint8_t *rx,
                                 uint16_t length, uint32_t timeout_ms)
{
    uint32_t start_ms;
    bsp_status_t result;
    if (!lcd_ready || !bsp_timebase_ready()) return BSP_ERROR_NOT_READY;
    if (DMA_LCM_CR & 0x80U) return BSP_ERROR_BUSY;
    start_ms = system_millis();
    PBCLRB = PIN_0;
    while (length--) {
        LCM_ClearFlag();
        if (tx) LCM_WriteData_8B(*tx++);
        LCM_SetCommand(command);
        result = lcd_wait(start_ms, timeout_ms);
        if (result != BSP_OK) return result;
        if (rx) *rx++ = LCM_ReadData_8B();
    }
    PBSETB = PIN_0;
    return BSP_OK;
}

bsp_status_t bsp_lcd_write_command(uint8_t command, uint32_t timeout_ms)
{
    return lcd_transfer(LCMCMD_SENDCMD, &command, 0, 1, timeout_ms);
}

bsp_status_t bsp_lcd_write_data(const uint8_t *data, uint16_t length, uint32_t timeout_ms)
{
    if (!length) return BSP_OK;
    if (!data) return BSP_ERROR_ARGUMENT;
    return lcd_transfer(LCMCMD_SENDDATA, data, 0, length, timeout_ms);
}

bsp_status_t bsp_lcd_read_data(uint8_t *data, uint16_t length, uint32_t timeout_ms)
{
    if (!length) return BSP_OK;
    if (!data) return BSP_ERROR_ARGUMENT;
    return lcd_transfer(LCMCMD_READDATA, 0, data, length, timeout_ms);
}

bsp_status_t bsp_lcd_read_status(uint8_t *status, uint32_t timeout_ms)
{
    if (!status) return BSP_ERROR_ARGUMENT;
    return lcd_transfer(LCMCMD_READSTAT, 0, status, 1, timeout_ms);
}

void bsp_lcd_backlight(uint8_t on)
{
    if (!lcd_ready) return;
    if (!!on == BSP_LCD_BACKLIGHT_HIGH) P9SETB = PIN_2;
    else P9CLRB = PIN_2;
}

bsp_status_t bsp_ctp_io_init(void)
{
    if (!system_is_ready()) return BSP_ERROR_NOT_READY;
    (void)bsp_board_prepare(BSP_RESOURCE_CTP);
    ctp_ready = 1;
    return BSP_OK;
}

void bsp_ctp_set_reset(uint8_t asserted)
{
    if (!ctp_ready) return;
    if (!!asserted == BSP_CTP_RESET_LOW) PBCLRB = PIN_6;
    else PBSETB = PIN_6;
}

uint8_t bsp_ctp_interrupt_active(void)
{
    uint8_t high;
    if (!ctp_ready) return 0;
    high = (PBIN & PIN_7) != 0;
    return BSP_CTP_IRQ_LOW ? !high : high;
}
