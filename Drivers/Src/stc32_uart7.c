#include "system_stc32.h"
#include "stc32_uart7.h"

#define UART7_BAUD    115200UL
/* Timer7 为 1T，UART7 波特率为溢出频率的 1/4；计数四舍五入。 */
#define UART7_COUNTS  ((SYSCLK + 2UL * UART7_BAUD) / (4UL * UART7_BAUD))
#define UART7_RELOAD  (65536UL - UART7_COUNTS)
#if UART7_COUNTS == 0 || UART7_COUNTS > 65535UL
#error "SYSCLK 超出 UART7 波特率发生器范围"
#endif

void stc32_uart7_init(void)
{
    /* 引脚与复用由 bsp_board_init() 准备，这里只配置控制器和 Timer7。 */
    UART7_DisableInt();  /* 例程轮询收发，不占用 UART7 中断向量。 */
    UART7_DisableTimeoutInt();
    UART7_DisableTimeout();
    UART7_NoneParity();
    S7CON = 0x50U;       /* 模式 1：8 位数据、允许接收。 */

    TIMER7_Stop();
    TIMER7_DisableInt();
    TIMER7_TimerMode();
    TIMER7_1TMode();
    TIMER7_DisableCLKO();
    TIMER7_SetPrescale(0);
    TIMER7_SetReload16((uint16_t)UART7_RELOAD);
    TIMER7_ClearFlag();
    UART7_Timer7BRT();   /* 写的是 T7H/T7L，选择并启动的也必须是 Timer7。 */
    TIMER7_Run();
}

void stc32_uart7_write(uint8_t byte)
{
    UART7_SendData(byte);
    while (!UART7_CheckTxFlag()) {
    }
    UART7_ClearTxFlag();
}

int stc32_uart7_try_read(void)
{
    if (UART7_CheckRxFlag()) {
        uint8_t byte = UART7_ReadData();
        UART7_ClearRxFlag();
        return byte;
    }
    return -1;
}
