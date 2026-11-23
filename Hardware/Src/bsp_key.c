#include "bsp_key.h"
#include "bsp_config.h"
#include "bsp_gpio.h"

static uint8_t stable_pressed;
static uint8_t sampled_pressed;
static uint8_t started;
static uint32_t changed_ms;

void bsp_key_init(void)
{
    /* P3.2 同时参与上电 USB ISP 判定；此处只影响进入用户程序后的状态。 */
    BSP_GPIO_INPUT(3, PIN_2, BSP_KEY_ACTIVE_LOW);
    stable_pressed = 0;
    sampled_pressed = 0;
    started = 0;
}

uint8_t bsp_key_read_raw(void)
{
    uint8_t high = (P3 & PIN_2) != 0;
    return BSP_KEY_ACTIVE_LOW ? !high : high;
}

bsp_key_event_t bsp_key_poll(uint32_t now_ms)
{
    uint8_t pressed = bsp_key_read_raw();
    if (!started) {
        /* 等上拉稳定后由主循环首次采样，记录上电时的实际状态。 */
        sampled_pressed = stable_pressed = pressed;
        changed_ms = now_ms;
        started = 1;
        return BSP_KEY_EVENT_NONE;
    }
    if (pressed != sampled_pressed) {
        sampled_pressed = pressed;
        changed_ms = now_ms;
    }
    if (sampled_pressed != stable_pressed &&
        (uint32_t)(now_ms - changed_ms) >= BSP_KEY_DEBOUNCE_MS) {
        stable_pressed = sampled_pressed;
        return stable_pressed ? BSP_KEY_EVENT_PRESSED : BSP_KEY_EVENT_RELEASED;
    }
    return BSP_KEY_EVENT_NONE;
}

uint8_t bsp_key_is_pressed(void)
{
    return stable_pressed;
}
