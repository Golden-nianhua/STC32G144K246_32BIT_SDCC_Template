#ifndef BSP_CONFIG_H
#define BSP_CONFIG_H

/* 已确认：P9.3 LED 高电平点亮。其余极性尚无原理图依据，集中放在此处修改。
 * KEY 暂按按下接地；RS485 暂按 DIR=1 发、DIR=0 收；LCD 暂按背光高亮。
 * 所有外设的引脚固定来自本板接线，完整接线见 Hardware/README.md。 */
#define BSP_KEY_ACTIVE_LOW       1
#define BSP_KEY_DEBOUNCE_MS      20UL
#define BSP_RS485_TX_HIGH        1
#define BSP_LCD_BACKLIGHT_HIGH   1
#define BSP_CTP_RESET_LOW        1
#define BSP_CTP_IRQ_LOW          1

/* LCD 控制器分频与总线建立/保持时间的原始字段值，见手册 32.2/32.3。
 * 初始采用较慢配置；确认屏幕控制器型号和时序后再提高速度。 */
#define BSP_LCD_PRESCALER        8U
#define BSP_LCD_SETUP           3U
#define BSP_LCD_HOLD            1U

/* 不启用外部 P1.6/P1.7 32K 晶振。CPU 主频见 system_stc32.h 中的 SYSCLK；
 * USB-ICE Debug 兼容配置为 48 MHz，正常配置为 90 MHz。
 * system_init 只启用 LED/KEY/UART7；其余总线由应用显式调用各自 init。 */

#endif
