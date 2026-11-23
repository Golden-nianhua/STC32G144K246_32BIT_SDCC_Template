#ifndef BSP_RS485_H
#define BSP_RS485_H

#include <stdint.h>
#include "bsp_common.h"

/* 两路 RS485 均使用 8N1 模式，轮询收发，不占用中断向量。
 * system_init() 后调用init；init内部准备引脚，并检查对应DMA占用。 */
bsp_status_t bsp_rs485_uart4_init(uint32_t baud);
bsp_status_t bsp_rs485_uart8_init(uint32_t baud);

/* 非阻塞读：有数据返回 BSP_OK 并写 *byte，无数据返回 BSP_ERROR_NOT_READY。
 * 参数错误返回ARGUMENT，DMA占用时返回BUSY。 */
bsp_status_t bsp_rs485_uart4_try_read(uint8_t *byte);
bsp_status_t bsp_rs485_uart8_try_read(uint8_t *byte);

/* 发送len字节；len=0时不碰总线。参数/未初始化/DMA忙时不开始发送。
 * 开始发送后无论成功或超时均恢复为接收态。
 * 首字节直接写入，后续字节才等待上一字节 TI；函数返回前额外保护等待至少
 * ceil(1 bit 时间)+1 ms，并计入整个 write 的超时预算。 */
bsp_status_t bsp_rs485_uart4_write(const uint8_t *buffer, uint16_t len,
                                   uint32_t timeout_ms);
bsp_status_t bsp_rs485_uart8_write(const uint8_t *buffer, uint16_t len,
                                   uint32_t timeout_ms);

#endif
