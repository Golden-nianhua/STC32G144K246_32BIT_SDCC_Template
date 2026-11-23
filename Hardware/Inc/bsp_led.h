#ifndef BSP_LED_H
#define BSP_LED_H

#include <stdint.h>

/* P9.3，高电平亮；初始化后灭。接口只修改这一位。 */
void bsp_led_init(void);
void bsp_led_set(uint8_t on);
void bsp_led_toggle(void);
uint8_t bsp_led_is_on(void);

#endif
