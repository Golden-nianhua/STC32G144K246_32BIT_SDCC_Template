#include "bsp_led.h"
#include "bsp_gpio.h"

void bsp_led_init(void)
{
    P9CLRB = PIN_3;
    BSP_GPIO_OUTPUT(9, PIN_3);
}

void bsp_led_set(uint8_t on)
{
    /* SETB/CLRB 寄存器只改指定的位，避免与 UART7/背光共用 P9 时互相覆盖。 */
    if (on) P9SETB = PIN_3;
    else P9CLRB = PIN_3;
}

void bsp_led_toggle(void)
{
    bsp_led_set(!bsp_led_is_on());
}

uint8_t bsp_led_is_on(void)
{
    return (P9OUT & PIN_3) != 0;
}
