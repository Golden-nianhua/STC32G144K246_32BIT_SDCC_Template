#ifndef BSP_I2C_H
#define BSP_I2C_H

#include <stdint.h>
#include "bsp_common.h"

/* I2C1 共享总线：P7.7 SCL、P7.6 SDA，7 位地址。
 * 地址参数始终传未移位的 0x00..0x7F，驱动自行生成 R/W 位。 */

#define BSP_I2C_DEFAULT_HZ 100000UL

/* 默认 100 kHz；任何速度都按 90 MHz 系统时钟重新计算合法分频。
 * init/事务开始前会检查 BUSY 和 I2C1 DMA；超时后驱动标记未就绪，
 * 必须重新调用本函数才能继续使用。 */
bsp_status_t bsp_i2c_init(uint32_t bus_hz);

/* 完整写事务：START + 地址(写) + 数据 + STOP。
 * len 为 0 时只发送地址并检查 ACK。从机 NACK 返回 BSP_ERROR_NACK。 */
bsp_status_t bsp_i2c_write(uint8_t address, const uint8_t *data, uint16_t len,
                           uint32_t timeout_ms);

/* 写后重复 START 读：写阶段可无（write_len=0），读阶段至少 1 字节。
 * write_len==0 时为纯读，只发送一次 R 地址；非最后字节回 ACK，
 * 最后一字节回 NAK，然后 STOP。 */
bsp_status_t bsp_i2c_write_read(uint8_t address,
                                const uint8_t *write_data, uint16_t write_len,
                                uint8_t *read_data, uint16_t read_len,
                                uint32_t timeout_ms);

/* 只发送地址（写方向）探测 ACK；NACK 会尝试 STOP，但只有 BUSY 已清零且
 * DMA 未占用时才继续可复用。 */
bsp_status_t bsp_i2c_probe(uint8_t address, uint32_t timeout_ms);

#endif
