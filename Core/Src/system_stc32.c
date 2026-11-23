#include "system_stc32.h"
#include "bsp_board.h"
#include "stc32_uart7.h"

#define CLOCK_SWITCH_DIV 10U
#define HIRC_HZ          64000000UL
#define TIMER1_COUNTS    (SYSCLK / 12UL / 1000UL)
#if TIMER1_COUNTS == 0 || TIMER1_COUNTS > 65535UL || SYSCLK % 12000UL != 0
#error "SYSCLK 无法用 Timer1 12T 产生整计数的 1 ms 时基"
#endif
#define TIMER1_RELOAD    (65536UL - TIMER1_COUNTS)

static volatile uint32_t uptime_ms;
static uint8_t initialized;

static void timer1_configure(uint16_t reload)
{
    TIMER1_Stop();
    TIMER1_DisableInt();
    TIMER1_TimerMode();
    TIMER1_12TMode();
    TIMER1_Mode0();  /* STC32 的模式 0 是 16 位自动重装。 */
    TIMER1_DisableGateINT1();
    TIMER1_SetPrescale(0);
    TIMER1_SetReload16(reload);
    TIMER1_ClearFlag();
}

static void clock_init(void)
{
    CLK_SYSCLK_Divider(CLOCK_SWITCH_DIV);
    AccessCodeFastest();  /* 降频后按本次 SYSCLK 设置 Flash 等待周期。 */
    AccessIXramFastest();
    CLK_HIRC_Enable();
    HIRC_64M();
    CLK_HIRC_WaitStable();
    CLK_MCLK_HIRC();
    CLK_MCLK2_BYPASS();

    CLK_IRC48M_Enable();
    CLK_IRC48M_WaitStable();
    CLK_HPLL2_Disable();
    CLK_HPLL2_IRC48M();
    CLK_HPLL2_PreDivider(8); /* 48 MHz / 8 = 6 MHz。 */
    CLK_HPLL2_Lock360MHz();
    CLK_HPLL2_Enable();

    /* 仍由 HIRC/10 驱动，借用 Timer1 等待约 1 ms，避免依赖 C 空转循环。 */
    timer1_configure((uint16_t)(65536UL -
        (HIRC_HZ / CLOCK_SWITCH_DIV + 11999UL) / 12000UL));
    TIMER1_Run();
    while (!TIMER1_CheckFlag()) {
    }
    TIMER1_Stop();
    TIMER1_ClearFlag();

#if defined(STC_USB_ICE_DEBUG)
    /* 与已抓包的 Keil 仿真测试例程采用相同的 IRC48M 主时钟来源。
     * 90 MHz 路径实测在切换后几条指令内失联；此方案仍需实板复测。
     * HPLL2 保留给 HSIO，避免外设分频常量与实际时钟来源不一致。 */
    CLK_MCLK2_IRC48M();
#else
    CLK_MCLK2_HPLL2D2();  /* 先在低分频速度下切换到 HPLL2/2。 */
#endif
    CLK_SYSCLK_Divider(BOARD_SYSCLK_DIV);
    CLK_HSIOCK_HPLL2D2(); /* SPI 等高速外设输入保持 180 MHz。 */
}

INTERRUPT(timer1_isr, TMR1_VECTOR)
{
    /* 当前分支的 ISR 自动保存 DPL/DPH，但遗漏 DPXL。
     * 本 ISR 访问 large 模型 XRAM，需要额外保护 24 位地址的高字节。
     * 此段 ISR 没有局部栈变量/C 调用，手工 PUSH/POP 保持成对。
     * 增加这些内容前须重新检查编译器生成的 ISR 栈帧。 */
#if defined(__SDCC_mcs251) && !defined(__SDCC_SYNTAX_FIX)
    __asm push 0x84 __endasm;
#endif
    ++uptime_ms;
#if defined(__SDCC_mcs251) && !defined(__SDCC_SYNTAX_FIX)
    __asm pop 0x84 __endasm;
#endif
}

void system_init(void)
{
    DisableGlobalInt();
    EnableAccessXFR();    /* P9、时钟和 UART7 都有远地址寄存器。 */
    clock_init();
    IAP_SetTimeBase();   /* IAP 时基与切换后的 SYSCLK 一致。 */

    bsp_board_init();
    stc32_uart7_init();
    timer1_configure((uint16_t)TIMER1_RELOAD);
    TIMER1_SetIntPriority(3);
    TIMER1_EnableInt();
    TIMER1_Run();
    EnableGlobalInt();
    initialized = 1;
}

uint8_t system_is_ready(void)
{
    return initialized;
}

uint32_t system_millis(void)
{
    uint8_t was_enabled = EA;
    uint32_t now;
    EA = 0;
    now = uptime_ms;
    EA = was_enabled;
    return now;
}
