#ifndef BSP_BOARD_H
#define BSP_BOARD_H

#include "bsp_common.h"

typedef enum {
    BSP_RESOURCE_UART7 = 0,
    BSP_RESOURCE_RS485_UART4,
    BSP_RESOURCE_RS485_UART8,
    BSP_RESOURCE_SPI2_SD,
    BSP_RESOURCE_I2C1,
    BSP_RESOURCE_LCD8080,
    BSP_RESOURCE_CTP,
    BSP_RESOURCE_CAN1,
    BSP_RESOURCE_CAN2,
    BSP_RESOURCE_USB
} bsp_resource_t;

/* system_init 内部调用：准备 LED、按键、UART7 的引脚。
 * 仅操作本板拥有的位，不整口覆盖 P9/PA/PB 的其他资源。 */
void bsp_board_init(void);
/* 配置引脚和复用，不启动控制器，不配置器件协议或产生总线事务。
 * 用在对应控制器 init 之前；不能在控制器传输期间重复调用。 */
bsp_status_t bsp_board_prepare(bsp_resource_t resource);

#endif
