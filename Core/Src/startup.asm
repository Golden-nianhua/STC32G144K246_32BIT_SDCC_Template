; 此版 sdld 的 SSEG 分配仍沿用 8051 的 256 字节上限。
; GSINIT0 先执行编译器启动代码，GSINIT1 在首次 C 调用前设置真正的 16 位 SPX。
; 这里是顺序执行的初始化片段，不是函数，不能添加 RET/ERET。
; 设置后首个 PUSH/ECALL 写入 00:0100；00:0100..00:3FFF 专用于栈。
    .module board_startup
    .area GSINIT1 (CODE)
    .globl __stc32_stack_init
__stc32_stack_init::
    mov 0x81,#0xFF
    mov 0x85,#0x00
