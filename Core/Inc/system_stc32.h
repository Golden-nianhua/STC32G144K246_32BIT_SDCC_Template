#ifndef SYSTEM_STC32_H
#define SYSTEM_STC32_H

#include <stdint.h>
#include "stc32g144k246.h"

/* HSIO 仍由 HPLL2/2 提供 180 MHz；CPU 主频按本次固件的编译配置选择。
 * Debug 的 USB-ICE 时钟兼容方案使用 IRC48M，正常固件使用 HPLL2/2/2。
 * 所有驱动统一从 SYSCLK 计算定时器、UART 与 IAP 参数。 */
#define BOARD_HPLL2_HZ   360000000UL
#define BOARD_HSIO_HZ    (BOARD_HPLL2_HZ / 2UL)
#if defined(STC_USB_ICE_DEBUG)
#define BOARD_SYSCLK_DIV 1U
#define SYSCLK           48000000UL
#else
#define BOARD_SYSCLK_DIV 2U
#define SYSCLK           (BOARD_HPLL2_HZ / 2UL / BOARD_SYSCLK_DIV)
#endif

/* SPI2 的输入由 HSIOCLK 提供，独立于 CPU 的 CLKDIV：当前为 180 MHz。
 * 外设驱动必须按实际输入源计算分频，不能直接套用 SYSCLK。 */

void system_init(void);
uint32_t system_millis(void);
uint8_t system_is_ready(void);
void system_idle(void);
/* SDCC 在含 main 的翻译单元中生成向量表，因此这里必须声明 ISR。 */
INTERRUPT(timer1_isr, TMR1_VECTOR);

#endif
