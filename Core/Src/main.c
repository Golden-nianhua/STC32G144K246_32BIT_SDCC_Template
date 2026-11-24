#include "system_stc32.h"
#include "bsp_led.h"
#include "bsp_key.h"
#include "stc32_uart7.h"

volatile uint8_t debug_u8 = 0x12;
volatile uint16_t debug_u16 = 0x3456;
volatile uint32_t debug_u32 = 0x789ABCDEUL;
volatile int16_t debug_i16 = -1234;

#if defined(STC_DEBUG_WATCH_DEMO)
struct debug_sample {
    uint32_t time_ms;
    float value;
    int16_t axes[3];
};

struct debug_watch {
    struct debug_sample samples[2];
    struct debug_flags {
        unsigned int active : 1;
        unsigned int slot : 1;
        signed int offset : 4;
    } flags;
    uint16_t updates;
};

union debug_word {
    uint32_t bits;
    float value;
    uint8_t bytes[4];
};

volatile struct debug_watch __XDATA debug_demo = {
    {{0UL, 1.5f, {120, -45, 980}}, {0UL, -2.5f, {-90, 35, 1001}}},
    {0, 0, -3},
    0,
};
volatile union debug_word __XDATA debug_word_view = {0x3FC00000UL};
volatile struct debug_sample __XDATA * volatile __XDATA debug_current = &debug_demo.samples[0];
const char __CODE debug_label[] = "SWD watch demo";
const char __CODE * volatile __XDATA debug_label_ptr = &debug_label[4];
#endif

int main(void)
{
    static const char __CODE greeting[] = "Hello STC32G144K246!\r\n";

    system_init();
    for (uint8_t i = 0; greeting[i] != '\0'; ++i) {
        stc32_uart7_write((uint8_t)greeting[i]);
    }
    uint32_t last_toggle = 0;
    int received = 0;
    uint32_t now = 0;
    bsp_key_event_t key = 0;

    last_toggle = system_millis();
    for (;;) {
        received = stc32_uart7_try_read();
        now = system_millis();
        debug_u32 = now;
        key = bsp_key_poll(now);
        if (received >= 0) {
            stc32_uart7_write((uint8_t)received);
        }
        if ((uint32_t)(now - last_toggle) >= 1000UL) {
            last_toggle = now;
            bsp_led_toggle();
#if defined(STC_DEBUG_WATCH_DEMO)
            debug_demo.updates++;
            debug_demo.flags.active = !debug_demo.flags.active;
            debug_demo.flags.slot = debug_demo.updates & 1u;
            debug_current = &debug_demo.samples[debug_demo.flags.slot];
            debug_current->time_ms = now;
            debug_word_view.value = debug_current->value;
#endif
        }
        if (key == BSP_KEY_EVENT_PRESSED) {
            static const char __CODE message[] = "KEY pressed\r\n";
            for (uint8_t i = 0; message[i] != '\0'; ++i) {
                stc32_uart7_write((uint8_t)message[i]);
            }
        }
        system_idle();
    }
}
