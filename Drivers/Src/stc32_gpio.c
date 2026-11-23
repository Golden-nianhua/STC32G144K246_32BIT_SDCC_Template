#include "stc32_gpio.h"
#include "bsp_led.h"

/* 兼容旧模板接口；开发板 LED 的引脚与有效电平统一由 BSP 管理。 */

void stc32_gpio_init(void)
{
    bsp_led_init();
}

void stc32_gpio_toggle(void)
{
    bsp_led_toggle();
}
