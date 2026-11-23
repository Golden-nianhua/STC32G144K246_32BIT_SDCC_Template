#ifndef BSP_QSPI_H
#define BSP_QSPI_H

#include "bsp_common.h"

typedef enum {
    BSP_QSPI_NONE = 0,
    BSP_QSPI_FLASH,
    BSP_QSPI_PSRAM
} bsp_qspi_device_t;

typedef struct {
    uint8_t prescaler;    /* SCK=SYSCLK/(prescaler+1)，范围0..255。 */
    uint8_t size_bits;    /* 控制器地址范围2^size_bits字节，范围1..32，按器件容量填写。 */
    uint8_t clock_high;   /* 0=SPI mode0，1=SPI mode3。 */
} bsp_qspi_config_t;

typedef struct {
    uint8_t instruction;
    uint8_t instruction_mode; /* 1=单线，2=双线，3=四线。必须有指令。 */
    uint8_t address_mode;     /* 0=无地址，1/2/3=单/双/四线。 */
    uint8_t address_bytes;    /* 有地址时1..4；无地址时0。 */
    uint32_t address;
    uint8_t dummy_cycles;     /* 0..31；双/四线读必须留至少1个周转时钟。 */
    uint8_t data_mode;        /* 0=无数据，1/2/3=单/双/四线。 */
} bsp_qspi_command_t;

/* 一个硬件QSPI，通过整组引脚复用服务两个器件。acquire不等待；控制器、FIFO或
 * DMA非空时返回BUSY且不改路由。每次acquire必须配对release，不支持嵌套。
 * FLASH=P7.0..5；PSRAM=P4.0/1/3/6/7+P5.4。PSRAM启用后P4.7用作IO3，
 * 会关闭此脚的外部复位功能。P1.6/P1.7外部32K晶振始终不启用。 */
bsp_status_t bsp_qspi_acquire(bsp_qspi_device_t device, const bsp_qspi_config_t *config);
bsp_status_t bsp_qspi_release(bsp_qspi_device_t device);
bsp_qspi_device_t bsp_qspi_owner(void);

/* 通用间接指令，硬件控制nCS；tx/rx二选一，length=0时两者均须为空。
 * 仅支持SDR、不含交替字节的指令。不会自行设置器件QE位、QPI模式或PSRAM寄存器。
 * timeout是整笔传输的毫秒预算。失败后请求ABORT并保留所有权，先abort再release。 */
bsp_status_t bsp_qspi_transfer(bsp_qspi_device_t device, const bsp_qspi_command_t *command,
                               const uint8_t *tx, uint8_t *rx, uint16_t length,
                               uint32_t timeout_ms);
bsp_status_t bsp_qspi_abort(bsp_qspi_device_t device, uint32_t timeout_ms);

#endif
