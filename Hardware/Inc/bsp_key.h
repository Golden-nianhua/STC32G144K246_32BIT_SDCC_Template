#ifndef BSP_KEY_H
#define BSP_KEY_H

#include <stdint.h>

typedef enum {
    BSP_KEY_EVENT_NONE = 0,
    BSP_KEY_EVENT_PRESSED,
    BSP_KEY_EVENT_RELEASED
} bsp_key_event_t;

void bsp_key_init(void);
uint8_t bsp_key_read_raw(void); /* 1=按下，极性由 bsp_config.h 定义。 */
/* 主循环定期调用，返回消抖后的单次按下/释放事件；不阻塞、不使用中断。
 * now_ms 传 system_millis()，相邻调用间隔宜 <=5ms。上电按住不产生按下事件。 */
bsp_key_event_t bsp_key_poll(uint32_t now_ms);
uint8_t bsp_key_is_pressed(void); /* 最近一次 poll 后的稳定状态。 */

#endif
