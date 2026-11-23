#ifndef BSP_GPIO_H
#define BSP_GPIO_H

#include "stc32g144k246.h"

/* BSP 内部端口配置：p 为预处理记号 0..9/A/B，mask 为本资源占用的位。
 * PxBP=1 时手动配置 PxM0/M1；双向外设在配置完成后另设 PxBP=0。
 * 调用 OUTPUT 之前必须先写输出锁存，避免切换为输出时产生错误电平。 */
#define BSP_GPIO_COMMON(p, mask) do { \
    PORT_SetManualMode(p, (mask)); \
    PORT_DisablePullUp(p, (mask)); \
    PORT_DisablePullDown(p, (mask)); \
    PORT_EnableSchmitt(p, (mask)); \
    PORT_SetSlewRateNormal(p, (mask)); \
    PORT_SetDrivingNormal(p, (mask)); \
    PORT_SetDigitalInput(p, (mask)); \
    PORT_DisableInt(p, (mask)); \
} while (0)

#define BSP_GPIO_OUTPUT(p, mask) do { \
    BSP_GPIO_COMMON(p, (mask)); \
    PORT_SetPushPullMode(p, (mask)); \
} while (0)

#define BSP_GPIO_INPUT(p, mask, pull_up) do { \
    BSP_GPIO_COMMON(p, (mask)); \
    PORT_SetHighZInputMode(p, (mask)); \
    PORT_EnablePullUp(p, (pull_up) ? (mask) : 0); \
} while (0)

#endif
