#ifndef STC32_COMPILER_H
#define STC32_COMPILER_H

#include <stdint.h>

/* CLion 的语法适配只用于代码分析，不能传给实际 SDCC 构建。 */
#if defined(__SDCC_SYNTAX_FIX)
#define SFR(name, addr) extern volatile unsigned char name
#define SBIT(name, addr, bit) extern volatile unsigned char name
#define __BIT unsigned char
#define __DATA
#define __IDATA
#define __PDATA
#define __XDATA
#define __FAR
#define __CODE
#define __REENTRANT
#define INTERRUPT(name, vector) void name(void)
#define INTERRUPT_USING(name, vector, bank) void name(void)
#define NOP1() do { } while (0)

#elif defined(__SDCC_mcs251)
/* 工程名称中的 32BIT 表示芯片系列，不能据此假设 C 的 int/指针为 32 位。 */
_Static_assert(sizeof(int) == 2, "MCS-251 ABI requires 16-bit int");
_Static_assert(sizeof(long) == 4, "MCS-251 ABI requires 32-bit long");
_Static_assert(sizeof(void *) == 3, "MCS-251 ABI requires 24-bit generic pointers");
#define SFR(name, addr) __sfr __at(addr) name
#define SBIT(name, addr, bit) __sbit __at((addr) + (bit)) name
#define __BIT __bit
#define __DATA __data
#define __IDATA __idata
#define __PDATA __pdata
#define __XDATA __xdata
#define __FAR __far
#define __CODE __code
#define __REENTRANT __reentrant
#define INTERRUPT(name, vector) void name(void) __interrupt(vector)
#define INTERRUPT_USING(name, vector, bank) void name(void) __interrupt(vector) __using(bank)
#define NOP1() do { __asm nop __endasm; } while (0)

#elif defined(__C251__)
/* 只适配源码语法；不能混合链接 Keil OMF251 与 SDCC .rel/.lib。 */
#include <intrins.h>
#define SFR(name, addr) sfr name = addr
#define SBIT(name, addr, bit) sbit name = addr ^ bit
#define __BIT bit
#define __DATA data
#define __IDATA idata
#define __PDATA pdata
#define __XDATA xdata
#define __FAR far
#define __CODE code
#define __REENTRANT reentrant
#define INTERRUPT(name, vector) void name(void) interrupt vector
#define INTERRUPT_USING(name, vector, bank) void name(void) interrupt vector using bank
#define NOP1() do { _nop_(); } while (0)

#else
#error "请使用支持 -mmcs251 的 SDCC 或 Keil C251；原版 SDCC MCS-51 不适用"
#endif

/* SDCC __sbit 只能表达经典 8051 位地址。
 * 非 8 字节对齐的 SFR 使用字节掩码访问；读改写与中断共享时需要临界区。 */
#define STC_READ_BIT(reg, bit) (((reg) >> (bit)) & 1U)
#define STC_WRITE_BIT(reg, bit, value) do { \
    (reg) = (unsigned char)(((reg) & (unsigned char)~(1U << (bit))) \
        | ((unsigned char)!!(value) << (bit))); \
} while (0)

/* 保留已有外设宏使用的 NOP(n) 接口。 */
#define NOP2() do { NOP1(); NOP1(); } while (0)
#define NOP3() do { NOP2(); NOP1(); } while (0)
#define NOP4() do { NOP2(); NOP2(); } while (0)
#define NOP5() do { NOP4(); NOP1(); } while (0)
#define NOP6() do { NOP4(); NOP2(); } while (0)
#define NOP7() do { NOP6(); NOP1(); } while (0)
#define NOP8() do { NOP4(); NOP4(); } while (0)
#define NOP9() do { NOP8(); NOP1(); } while (0)
#define NOP10() do { NOP8(); NOP2(); } while (0)
#define NOP11() do { NOP10(); NOP1(); } while (0)
#define NOP12() do { NOP8(); NOP4(); } while (0)
#define NOP13() do { NOP12(); NOP1(); } while (0)
#define NOP14() do { NOP12(); NOP2(); } while (0)
#define NOP15() do { NOP14(); NOP1(); } while (0)
#define NOP16() do { NOP8(); NOP8(); } while (0)
#define NOP17() do { NOP16(); NOP1(); } while (0)
#define NOP18() do { NOP16(); NOP2(); } while (0)
#define NOP19() do { NOP18(); NOP1(); } while (0)
#define NOP20() do { NOP16(); NOP4(); } while (0)
#define NOP21() do { NOP20(); NOP1(); } while (0)
#define NOP22() do { NOP20(); NOP2(); } while (0)
#define NOP23() do { NOP22(); NOP1(); } while (0)
#define NOP24() do { NOP16(); NOP8(); } while (0)
#define NOP25() do { NOP24(); NOP1(); } while (0)
#define NOP26() do { NOP24(); NOP2(); } while (0)
#define NOP27() do { NOP26(); NOP1(); } while (0)
#define NOP28() do { NOP24(); NOP4(); } while (0)
#define NOP29() do { NOP28(); NOP1(); } while (0)
#define NOP30() do { NOP28(); NOP2(); } while (0)
#define NOP31() do { NOP30(); NOP1(); } while (0)
#define NOP32() do { NOP16(); NOP16(); } while (0)
#define NOP33() do { NOP32(); NOP1(); } while (0)
#define NOP34() do { NOP32(); NOP2(); } while (0)
#define NOP35() do { NOP34(); NOP1(); } while (0)
#define NOP36() do { NOP32(); NOP4(); } while (0)
#define NOP37() do { NOP36(); NOP1(); } while (0)
#define NOP38() do { NOP36(); NOP2(); } while (0)
#define NOP39() do { NOP38(); NOP1(); } while (0)
#define NOP40() do { NOP32(); NOP8(); } while (0)
#define NOP(n) NOP##n()

#endif
