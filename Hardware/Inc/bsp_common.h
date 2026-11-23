#ifndef BSP_COMMON_H
#define BSP_COMMON_H

#include <stdint.h>

typedef enum {
    BSP_OK = 0,
    BSP_ERROR_ARGUMENT,
    BSP_ERROR_TIMEOUT,
    BSP_ERROR_BUSY,
    BSP_ERROR_NOT_READY,
    BSP_ERROR_NACK,
    BSP_ERROR_IO
} bsp_status_t;

/* 带毫秒超时的接口仅供主循环使用，调用前须完成 system_init() 并开启中断。
 * 不在中断中调用 BSP 总线函数；所有总线均为单调用者、轮询式接口。 */
uint8_t bsp_timebase_ready(void);

#endif
