; sdas251 / ASxxxx Source 模式汇编示例。
; 原生 C 调用采用 ECALL，返回必须使用 ERET，不能照搬 8051 的 RET。
    .module idle
    .area CSEG (CODE)
    .globl _system_idle
_system_idle::
    nop
    eret
