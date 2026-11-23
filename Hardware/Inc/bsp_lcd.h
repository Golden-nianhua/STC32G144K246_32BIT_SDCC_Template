#ifndef BSP_LCD_H
#define BSP_LCD_H

#include "bsp_common.h"

/* 8080 8位硬件总线：P2 数据，P4.5 DC、P4.4 RD、P4.2 WR、PB.0 CS。
 * 不发送任何面板初始化序列，背光初始化为关闭。时序集中在 bsp_config.h。 */
bsp_status_t bsp_lcd_bus_init(void);
bsp_status_t bsp_lcd_write_command(uint8_t command, uint32_t timeout_ms);
bsp_status_t bsp_lcd_write_data(const uint8_t *data, uint16_t length, uint32_t timeout_ms);
bsp_status_t bsp_lcd_read_data(uint8_t *data, uint16_t length, uint32_t timeout_ms);
bsp_status_t bsp_lcd_read_status(uint8_t *status, uint32_t timeout_ms);
/* 这里只提供背光开关。P9.2 的 PWMF7 路由已在接线表记录，暂不占用整组 PWMF。 */
void bsp_lcd_backlight(uint8_t on);

/* CTP 只准备 PB.6 RESET/PB.7 INT；I2C1 需另行初始化。
 * 不猜测触控芯片的 I2C 地址选择时序；复位脉宽、INT 电平采样由器件驱动负责。 */
bsp_status_t bsp_ctp_io_init(void);
void bsp_ctp_set_reset(uint8_t asserted);
uint8_t bsp_ctp_interrupt_active(void);

#endif
