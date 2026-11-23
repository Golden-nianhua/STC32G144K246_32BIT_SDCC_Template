# STC32G144K246 原生 MCS-251 SDCC 模板

参照 STC89 模板组织的 CLion/CMake 单固件工程。使用 [sdcc-c251](https://github.com/gevico/sdcc-c251) 的原生 `-mmcs251` 后端与 `sdas251`，不再把 STC32G 当作 8 位 MCS-51 目标编译。

本工程放在现有目录 `STC32K144G246_32BIT_SDCC_Template` 下，固件名与预设采用头文件和官方资料中的正确型号 **STC32G144K246**。工程提供构建、代码分析、固件检查，以及基于 STCForge `stc-isp` 的芯片 USB-HID ISP 下载。

## 首次构建

需要 CMake 3.21+、Ninja、uv 和包含 MCS-251 后端的完整 SDCC 安装包。工具路径统一在根目录 `CMakeLists.txt` 顶部填写，Debug 和 Release 共用：

```cmake
set(SDCC_BIN "D:/Code/c-env/SDCC/SDCC-4.6.0-MCS251/bin")
set(STCFORGE_BIN "D:/Projects/stcforge/dist/windows")
```

- `SDCC_BIN` 填 `sdcc.exe` 所在目录。保留完整的 SDCC 安装（包括同级 `include`、`lib` 等），不用改系统 `PATH`。
- `STCFORGE_BIN` 填 `stc-isp.exe`、`stcforge.exe` 所在目录。若使用便携包，填解压后的 `bin/`；CLion 自定义调试器选同目录的 `stc-gdb.exe`。留空则从 `PATH` 查找下载器和调试服务端。
- 本机的 MCS-251 包中 `sdar/sdranlib` 缺 DLL，因此 `SDCC_ARCHIVE_BIN` 指向原版 SDCC 的 `bin`。MCS-251 包的归档工具能正常启动时留空即可。
- uv 用于链接后的 HEX/BIN 打包与检查。已在 `PATH` 中时，`UV_EXECUTABLE` 可以留空。

```powershell
cmake --preset STC32G144K246-Debug
cmake --build build/Debug

cmake --preset STC32G144K246-Release
cmake --build build/Release
```

从旧配置迁移或更换 SDCC 时，重置 CMake 缓存再重新加载。编译直接运行 `sdcc`，原来被过滤的宏重定义和 `DPTR no-match` 诊断会原样输出。

## 目录

```text
Core/Inc、Core/Src       应用、系统时基、原生汇编和板级栈初始化
Drivers/Inc             编译器适配、芯片寄存器、已有外设宏和基础类型
Drivers/Src             UART7 轮询收发及旧 GPIO 接口兼容入口
Hardware/Inc、Src       开发板 BSP、引脚复用和按需启用的总线接口
Misc/                   CLion 自定义编译器定义、stc-isp 本机配置及示例
cmake/                  SDCC 工具链、sdas251 模块、目标和运行配置模板
tools/build/firmware.py 链接后打包 HEX/BIN 并检查布局
build/Debug/firmware/   Debug 固件，Release 路径结构相同
```

在 `CMakeLists.txt` 的 `target_sources`（或 `add_executable` 源码列表）中显式加入新源文件；三个 `Inc` 目录已加入头文件搜索路径。

## CLion 与 targets

直接打开工程根目录，启用 `STC32G144K246-Debug` / `STC32G144K246-Release` 两个 CMake 预设。普通 CMake profile 也会自动加载本工程工具链。

这里只声明 configure presets，避免 CLion 将 configure/build presets 分别导入后出现两组 Debug/Release。

预设使用名为 `MCS-251` 的 CLion 工具链，集中配置 SDCC、CMake/Ninja 和 STCForge GDB；具体路径与调试方式见 [STCForge 调试说明](Misc/STCFORGE_DEBUG.md)。编译和链接约定仍由工程 toolchain 文件设置。安装并启用 **Custom Defined Compiler** 插件后，工程的 `.idea/custom-compiler.xml` 会引用 `Misc/custom-compiler-sdcc-mcs251.yaml`；也可在 Settings → Build, Execution, Deployment → Custom Defined Compiler 中手动选择该 YAML。

首次 CMake 配置会生成运行配置，沿用 STC89 的文件夹组织：

| 文件夹 | 配置 | 点击运行的效果 |
|---|---|---|
| App | `STC32G144K246_32BIT_SDCC_Template` | 构建所选 profile 的固件 |
| App | `STC32G144K246_32BIT_SDCC_Template_flash` | 先构建，再通过 USB-HID 下载，关闭 ICE，保留其他硬件选项和 IRC |
| App | `STC32G144K246_32BIT_SDCC_Template_flash_with_options` | 先构建，再通过 USB-HID 下载，关闭 ICE，并写入 TOML 中的硬件选项 |
| tools | `stc_info` | 读取芯片型号、BSL 版本、保存的 IRC 频率和当前硬件选项 |
| tools | `stc_debug_enable` | 按 `Misc/stcforge.toml` 启用仿真。走 ISP，会擦除程序区；USB 模式同时下载当前 Debug 固件 |
| 独立入口 | `STCForge_debug` | 构建并启动调试。启用 `swd_sync_flash` 时 SWD 只更新不同的页；USB-ICE 直接连接 |

命令行目标：

```powershell
cmake --build build/Debug --target STC32G144K246_32BIT_SDCC_Template
cmake --build build/Debug --target stc_info
```

Debug / Release 并行配置时通过文件锁协调运行配置生成。生成的 XML 和构建产物均已忽略。代码分析采用接近 SDCC 整数宽度的分析目标；CLion 无法精确模拟 24 位指针与大端 ABI，实际行为以 SDCC 编译结果为准。

## USB-HID ISP 下载（默认）

下载配置直接交给 `STCFORGE_BIN` 中的 `stc-isp`，实际 HID 协议由 STCForge 实现。

直接编辑模板随附的两份配置：`Misc/stc-isp.toml` 用于下载和 `stc_info`，`Misc/stcforge.toml` 用于启用仿真和调试。CMake 不生成或覆盖这两份文件。

STC32G144K246 的串口可用于 ISP 下载，但不支持 UART 仿真。调试可选 `usb` 或 `swd`；USB 模式更换固件后，在 CLion 运行 `stc_debug_enable`，它会先构建 Debug、下载该次生成的 HEX 并启用 USB-ICE。

先检查配置，再让板卡进入芯片自身的 USB ISP 模式。Windows 应识别为 **HID 34BF:1001**，不需要串口号或波特率；同时只连接一块待下载芯片，并关闭占用它的 AiCube-ISP。

```powershell
stc-isp.exe --config Misc/stc-isp.toml --dry-run
stc-isp.exe --config Misc/stc-isp.toml --info

$image = 'build/Debug/firmware/STC32G144K246_32BIT_SDCC_Template.hex'
stc-isp.exe --config Misc/stc-isp.toml --dry-run --image $image
stc-isp.exe --config Misc/stc-isp.toml --image $image --option modify_hardware_options=false --option usb_ice_enabled=false
stc-isp.exe --config Misc/stc-isp.toml --image $image --option modify_hardware_options=false --option usb_ice_enabled=true
```

`--dry-run` 校验配置，指定 `--image` 时还会检查 Intel HEX 格式。`--info` 读取当前芯片状态。普通下载通过 `modify_hardware_options=false` 保留当前硬件选项并关闭 ICE，带选项下载直接使用 TOML，仿真下载只追加 `usb_ice_enabled=true`。

CLion 的两个 `..._flash*` 配置都绑定固件构建目标，运行前先构建，再把 `$CMakeCurrentProductFile$` 交给 `stc-isp.exe`。生成时默认选择 Debug；需要下载 Release 时，在运行配置的 CMake profile 中选择 `STC32G144K246-Release`，产品宏会使用该 profile 的固件，不写死 `build/Debug`。该产品通常为 `.ihx`，与 `.hex` 一样保留完整绝对地址，下载器均可解析。工具配置直接执行，不附加运行前构建任务。普通构建不会触发下载。

硬件复选框使用 `true/false`，配置中逐项说明官方界面含义。CPU 模式固定为本模板所需的 32 位；容量、看门狗分频和低压门槛使用整数。看门狗分频只接受 `2、4、8、16、32、64、128、256`。

示例配置默认不填写 IRC 调节项，因此即使执行 `flash-with-options` 也保留芯片保存的 IRC 参数，应用在 `system_init()` 中配置运行时钟。需要调节时，按下载配置中的注释填写 `[hardware]` 下的 `irc_adjust_mode` 和 `irc_hz`。

下载文件应使用带绝对地址的 HEX/IHX，程序入口为 `FF0000`。同一 HEX 可包含从 `FC2800` 开始的 EEPROM 数据；协议会在擦除前检查芯片当前分区，以及本次配置的新分区。带 EEPROM 数据时，从 `FC2800` 开始擦除，先写 EEPROM，再写程序；普通程序下载从 `FF0000` 开始，EEPROM 是否擦除仍受芯片原有设置影响。配置中的“下次下载擦除 EEPROM”在本次固件之后写入。

当前集成已通过 Debug/Release 固件检查、TOML 配置检查，以及包含完整模拟 HID 下载的离线测试。验证时未检测到处于 USB ISP 模式的设备，真实板卡下载仍待确认。

下载仅保留两个 `..._flash*` 共享运行配置；不再额外创建重复的 `stc_flash*` CMake 下载目标。命令行直接使用上面的 `stc-isp.exe` 命令。

## 内存、ABI 与固件

布局来自本机官方 STC32G144K246 Keil 示例的设备配置，并结合分支编译器的启动约定：

| 区域 | 地址 | 用途 |
|---|---|---|
| 模板默认程序区 | `FF:0000..FF:FFFF`（64 KiB） | 启动、程序、常量 |
| HOME | `FF:0000` 起 | 复位入口和中断向量；复位跳板使用 24 位 EJMP 转到启动代码 |
| 启动 | 紧跟 HOME | 编译器启动及 C 数据初始化 |
| edata | `00:0000..00:3FFF`（16 KiB） | 低 256 字节用于 near 数据，余下 16128 字节预留给 SPX |
| xdata | `01:0000..02:FFFF`（128 KiB） | large 模型的普通静态变量 |

工程统一使用 `--model-large --stack-auto --int-long-reent`，并链接 `mcs251-large-stack-auto` 配套库。所有翻译单元必须保持 ABI 一致：`int` 为 16 位，`long` 为 32 位，generic/far/code 指针为 24 位，多字节对象为大端。`32BIT` 不代表 `sizeof(int) == 4`。`compiler.h` 内有编译期宽度检查。

分支后端生成 **Source/251 模式** 指令，启动代码不修改 `AUXR2.CPUMODE`。普通函数使用 `ECALL/ERET`，中断返回使用 `RETI`。不要加入 STC89 的 8051 汇编文件。

此版 `sdld` 的 SSEG 分配仍限制在低 256 字节，直接设置 `--stack-size 0x3F00` 会链接失败。因此链接器只保留一个 SSEG 启动占位；`Core/Src/startup.asm` 在 `GSINIT1`、首次 C 调用前将 SPX 设置为 `0x00FF`，之后栈从 `0x0100` 向高地址增长。不要删除该文件，也不要在普通 C 函数里重设 SP/SPH。`.mem` 中的 SSEG 占位大小不是实际可用栈大小，实际栈峰值仍需上板测量。

固件包括 `.ihx`、`.hex`、`.bin`、`.map`、`.mem`。HEX 保留完整的 24 位绝对地址；BIN 从 `0xFF0000` 开始，空洞填充 `0xFF`。在 AiCube-ISP 中打开程序文件时优先选择新构建的 `.hex`。

芯片最多有 246 KiB 用户 Flash，但低地址扩展区与 EEPROM 共用。模板默认只用最高 64 KiB，避免启动代码落到 ISP 当前划给 EEPROM 的区域。如果确实需要超过 64 KiB，再按实际 EEPROM 分区配置扩展代码区，并同步调整链接和固件校验。

链接后会检查 Flash/XRAM 越界、near 数据与栈冲突、代码段重叠、复位入口和栈初始化，并显示空间统计。需要核对已有 HEX/BIN 时可用 `tools/build/firmware.py --check`（参数见 `--help`）。

当前编译器对本示例 ISR 生成的入口代码会保存 DPL/DPH，但遗漏 DPXL。`system_stc32.c` 已为访问 XRAM 的 Timer1 ISR 显式添加 DPXL 保存和恢复。该 ISR 没有局部栈变量或 C 函数调用；扩展 ISR 或升级编译器后，应从反汇编复核寄存器保存和栈帧，构建脚本不检查 ISR 现场保护。

## 头文件迁移与使用

应用统一包含 `stc32g144k246.h`，可直接使用仓库已生成的寄存器头文件。

`Drivers/Inc/stc32g144k246_reg.h` 从 TXT 自动生成：保留 SFR 地址、远地址寄存器和中断号，删除特定 Keil 版本的 `main` 宏 workaround，采用本工程的编译器适配层。寄存器地址使用 `__far` 24 位指针，未截断为 8 位 SDCC 的 16 位 xdata 地址。已有 `stc32g144k246_def.h` 外设宏和 `def.h` 类型定义放在 `Drivers/Inc`，后续使用具体外设时仍需按手册核对配置步骤。

经典可位寻址 SFR（地址低三位为 0）仍支持 `P10 = 1`、`EA = 0` 等写法。其他 SFR 的官方 `sbit` 别名改为读表达式和显式 setter，例如：

```c
unsigned char enabled = EAXFR;  /* 读取 P_SW2.7。 */
EAXFR_Set(1);                  /* 掩码设置 P_SW2.7。 */
EAXSFR();                      /* 同样启用扩展寄存器访问。 */
P_SW2 |= 0x80U;                /* 也可直接按字节操作。 */
```

旧移植头文件对这些非经典位一律使用 `__at(addr + bit)` 会错误映射位地址，不能照搬。字节读改写若与 ISR 共享寄存器，需要临界区。

SDCC 与 Keil C251 的源码适配宏集中在 `compiler.h`，涵盖 SFR、地址空间、中断和 NOP。此工程已验证 SDCC 构建；未提供已验证的 Keil 工程，SDCC `.rel/.lib` 也不能与 Keil OMF251 混合链接。

## 板卡例程

| 引脚 | 用途 | 配置 |
|---|---|---|
| P9.3 | LED | 高电平亮、上电灭，每 1000 ms 翻转 |
| P9.0 | UART7 RXD | 高阻输入、内部上拉、数字输入 |
| P9.1 | UART7 TXD | 推挽、空闲高电平 |
| P3.2 | KEY | 暂按低电平有效、内部上拉；20 ms 消抖后按下打印 KEY pressed |

完整板卡接线、BSP接口、按需启动方法与当前支持范围见 [Hardware/README.md](Hardware/README.md)。板级极性与LCD时序集中在 Hardware/Inc/bsp_config.h。

`system_init()` 先启用扩展寄存器访问并降频，设置 Flash 等待周期和内部 XRAM 访问速度。切换时先用工厂预置的 64 MHz HIRC，再用内部 48 MHz IRC 驱动 HPLL2：输入除以 8、PLL 设为 360 MHz。正常配置选择 HPLL2/2，经 `CLKDIV=2` 得到 **90 MHz SYSCLK**；Debug 默认打开 `STC_USB_ICE_SAFE_CLOCK`，CPU 改为 IRC48M / 1 的 **48 MHz**，用于排查原生 USB 仿真在时钟切换附近失联，尚需实板复测。HSIO 始终保留 HPLL2/2 的 180 MHz。切换后按各自 SYSCLK 更新 IAP 的 1 µs 时基、Timer1 和 UART7。时钟配置和频率定义在 `system_stc32.c/.h`，旧的 `STC_SYSCLK_HZ` CMake 变量不再参与计算。调试时钟方案和重下载步骤见 `Misc/STCFORGE_DEBUG.md`。

Timer1 用 12T、模式 0（16 位自动重装）提供 1 ms 时基，90 MHz 下重载值为 `0xE2B4`。启动时短暂借用 Timer1 等待 HPLL2 稳定，切换完成后再启用毫秒中断。所有 ISR 均应在 `main` 可见的头文件中声明，本工程使用 `INTERRUPT(timer1_isr, TMR1_VECTOR);`，否则 SDCC 可能漏生成向量。

UART7 使用 Timer7 的 1T 时钟，重载值为 `0xFF3D`，串口终端设为 **115200、8N1**。上电发送一次 `Hello STC32G144K246!`，随后回显收到的字节；P3.2按键消抖后按下发送一次 `KEY pressed`。此例使用轮询，适合手动收发验证；连续高速收发可再扩展为中断和缓冲区。LCD、RS485、SD、I2C、QSPI、CAN和USB应用协议栈均由应用按需启用，外部32K晶振保持关闭。

此前的P9.3 LED、UART7和默认地址布局已在用户板卡上验证。本次BSP扩展须在构建与寄存器模拟检查之后，按外设逐项重新上板验证。

参考：[编译器 MCS-251 后端说明](https://github.com/gevico/sdcc-c251/blob/main/doc/mcs251/README.md)、[ABI 说明](https://github.com/gevico/sdcc-c251/blob/main/doc/mcs251/abi.md)、[STC 官方芯片规格](https://stcmicro.com/cn/stc/stc32g144k246.html)、[STC 时钟例程](https://www.stcaimcu.com/thread-24684-1-1.html)。
