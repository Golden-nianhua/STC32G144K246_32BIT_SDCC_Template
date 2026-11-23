#include "system_stc32.h"
#include "bsp_led.h"
#include "bsp_key.h"
#include "stc32_uart7.h"

volatile uint8_t debug_u8 = 0x12;
volatile uint16_t debug_u16 = 0x3456;
volatile uint32_t debug_u32 = 0x789ABCDEUL;
volatile int16_t debug_i16 = -1234;

int main(void)
{
    static const char __CODE greeting[] = "Hello STC32G144K246!\r\n";

    system_init();
    for (uint8_t i = 0; greeting[i] != '\0'; ++i) {
        stc32_uart7_write((uint8_t)greeting[i]);
    }
    uint32_t last_toggle = system_millis();
    for (;;) {
        int received = stc32_uart7_try_read();
        uint32_t now = system_millis();
        debug_u32 = now;
        bsp_key_event_t key = bsp_key_poll(now);
        if (received >= 0) {
            stc32_uart7_write((uint8_t)received);
        }
        if ((uint32_t)(now - last_toggle) >= 1000UL) {
            last_toggle = now;
            bsp_led_toggle();
        }
        if (key == BSP_KEY_EVENT_PRESSED) {
            static const char __CODE message[] = "KEY pressed\r\n";
            for (uint8_t i = 0; message[i] != '\0'; ++i) {
                stc32_uart7_write((uint8_t)message[i]);
            }
        }
        //system_idle();
    }
}
