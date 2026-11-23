#ifndef STC32_UART7_H
#define STC32_UART7_H

#include <stdint.h>

/* 先由 BSP 准备 UART7 引脚；system_init() 已按顺序完成两层初始化。 */
void stc32_uart7_init(void);
void stc32_uart7_write(uint8_t byte);
/* 返回 -1 表示没有数据，否则返回 0..255。 */
int stc32_uart7_try_read(void);

#endif
