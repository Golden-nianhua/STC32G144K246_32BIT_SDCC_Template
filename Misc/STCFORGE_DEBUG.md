# CLion / STCForge 调试

## 一次性准备

在 CLion 的“设置 → 构建、执行、部署 → 工具链”创建名为 `MCS-251` 的工具链。

| 字段 | 本机设置 |
|---|---|
| 工具集 | MinGW，内置 Bundled MinGW |
| CMake | `C:/Program Files/JetBrains/CLion 2026.1/bin/cmake/win/x64/bin/cmake.exe` |
| 构建工具 | `C:/Program Files/JetBrains/CLion 2026.1/bin/ninja/win/x64/ninja.exe` |
| C 编译器 | `D:/Code/c-env/SDCC/SDCC-4.6.0-MCS251/bin/sdcc.exe` |
| C++ 编译器 | 本工程只启用 C 和汇编，不使用此字段 |
| 调试器 | 自定义 GDB：`D:/Projects/stcforge/dist/windows/stc-gdb.exe` |

自定义 GDB 现已默认开启 MI 异步模式，CLion 可以在目标运行期间发送暂停。更新后结束旧调试会话再启动，调试器路径不需要改。

内置 MinGW 提供 Windows 构建环境，实际固件由 SDCC 编译。`sdcpp.exe` 是预处理器，
不提供 C++ 支持。Custom Defined Compiler 的 YAML 继续用于 SDCC 代码分析。

`CMakePresets.json` 的公共预设已使用 `vendor["jetbrains.com/clion"].toolchain` 绑定
`MCS-251`；Debug、Release 继承该绑定。导入的预设在 CLion 中只读，修改 JSON 后重新加载。
GDB 的选择来自这套 CLion 工具链，CMake 的 `toolchainFile` 则负责 SDCC 编译和链接。

在模板根目录 `CMakeLists.txt` 顶部填写 `STCFORGE_BIN`；若使用 STCForge 便携包，填解压后的 `bin/`。
同一个目录里的 `stc-isp.exe` 用于下载，`stcforge.exe` 用于符号转换和启动服务端，
`stc-gdb.exe` 选作 CLion 工具链的调试器。各模板工程可共用这份运行目录，不需要 STCForge 源码路径。
便携包自带 Python 与 GDB 运行库，换机器时保留完整解压目录即可。源码开发版的安装方式见 STCForge 的 `docs/build.md`。
未指定 `STCFORGE_BIN` 时从 `PATH` 查找，缺少下载器或调试服务端也可以单独编译固件。

直接编辑模板随附的 `Misc/stcforge.toml`。在 `[stcforge]` 里用 `simulation_mode = "swd"` 或
`"usb"` 选择调试方式，配套的 ISP 参数放在同一个文件的 `[simulation_isp]`。普通下载和 `stc_info`
才使用另一份 `Misc/stc-isp.toml`。CMake 不生成或覆盖这两个文件。
STC32G144K246（F8D1）在 AiCube 中只支持 USB 和 SWD 仿真；UART 可用于 ISP 下载，但不是此型号的调试后端。
修改 GDB 端口或启动等待时间后重新加载 CMake。
默认启动等待为 3000 ms，为探针握手和 CPU 快照确认预留时间。

## 启用仿真与调试入口

`stc_debug_enable` 和 `stc_info` 位于 CLion 的 `tools` 分组，`STCForge_debug` 是独立调试入口：

| 配置 | 作用 |
|---|---|
| `stc_debug_enable` | 点“运行”，按 TOML 进入 USB-ICE 或制作 SWD 仿真芯片。通过 ISP 擦写，可能按原有设定擦除 EEPROM；日常调试不执行这一步 |
| `STCForge_debug` | 点“调试”，构建 Debug 固件和 ELF，按 TOML 启动 USB-ICE 或 Link1D SWD |

选择配置后点击“调试”，CLion 自动执行：构建 Debug 固件 → 生成调试 ELF → 启动 STCForge
服务端 → 使用 `MCS-251` 工具链中的 GDB 连接 `127.0.0.1:3333`。停止调试后服务端随会话退出。
这些调试入口固定采用 `STC32G144K246-Debug`。

USB 入口要求芯片已经进入 ICE。ISP → ICE 切换由模板调用的 STCForge `stc-isp` 完成；
已有启动抓包中下载的是原始用户程序，随后通过配置位切换，未出现单独的监控固件。
先让板卡进入 USB-ISP（`34BF:1001`），关闭占用设备的官方工具，再运行 `stc_debug_enable`。
该操作先构建 Debug，再下载与调试器共用的 `.hex` 并请求切换到 USB-ICE（`34BF:1002`），
保留其他硬件选项和 IRC。选中 Release 或缺少 HEX 时会直接报错。
切换成功后选择 `STCForge_debug`，点击“调试”。

USB 模式只连接 ICE，不会靠本地文件时间判断板上程序，也不自动重复下载。目标中运行的程序必须与本次构建 HEX 一致，
STCForge 的代码读取和断点恢复依赖该镜像。启动 USB 服务端会按 Keil 顺序查询版本、发送 FF0000 入口请求、等待 2 秒并读取状态，建立从程序入口开始的新调试会话；不会先发送暂停命令。
修改用户代码后需要重新进入 ISP，执行启用下载，再开始新的调试会话。

## Link1D SWD

1. 目标还未启用 SWD 时，检查 `Misc/stcforge.toml` 中的 ISP 接口、供电方式和仿真引脚，在 CLion 运行 `stc_debug_enable`。制作后给目标重新上电（若工具已完成自动重上电，无需手动重复）。已经启用 SWD 的板卡跳过此步。
2. 使用默认引脚时，将 Link1D 的 **S-P3.0 / SWDDAT** 接到板卡 **P3.0**，**S-P3.1 / SWDCLK** 接到 **P3.1**，两端共地。这两个引脚也接到板卡的 USB 接口，使用 SWD 时拔掉板卡的 USB 数据线。[STC 官方接线说明](https://www.stcaimcu.com/plugin.php?action=gooddetail&gid=3&id=xiaomy_exchange%3Aexchange)
3. 选 `STCForge_debug`。GDB 服务启动前，先用 Link1D 回读并比较 Debug HEX 涉及的代码页。相同的页跳过，只有不同的页擦写并回读校验。比较、下载或校验失败时，不启动调试。

SWD 同步只处理 HEX 涉及的代码页，页内未定义字节按 `FF` 处理，不修改 EEPROM 或硬件选项。SWD 调试从芯片读取程序代码，使用本次构建的 ELF 定位源码和变量。

在 PowerShell 中可先枚举探针，再单独检查连接及寄存器回读：

```powershell
& D:/Projects/stcforge/dist/windows/stcforge.exe list --swd
& D:/Projects/stcforge/dist/windows/stcforge.exe swd-probe
```

在 `Misc/stcforge.toml` 可设置共用速度 `swd_speed_khz`（默认 600，可选 100、300、600、1000）。多个 Link1D 时填写 `swd_device_path`。改完重新加载 CMake。
SWD 入口的 GDB 命令和符号流程已通过离线联调，实板待验收。

## 当前的时钟兼容排查配置

实板逐指令执行旧版 90 MHz 固件时，SDCC 启动和进入 `clock_init()` 均正常；
在切换 HPLL2/2、将 CLKDIV 设为 2 后，执行到旧镜像 `FF03BB` 处失去回复。
该位置在设置 HSIO 时钟前，不能据此认定是 HSIO 写入造成，也不能认定 USB 仿真只支持 48 MHz。
现有手册抽取内容没有找到 USB-ICE 的专用主频限制。

为隔离这个问题，`STC_USB_ICE_SAFE_CLOCK` 默认开启，但只作用于 Debug：

- Debug：CPU 选择 IRC48M / 1，`SYSCLK=48000000`，WTST=1。
- Release：CPU 仍为 HPLL2 / 2 / 2，`SYSCLK=90000000`，WTST=2。
- HSIO 在两种配置中均使用 HPLL2 / 2，即 180 MHz；UART7、Timer1 和 IAP 按各自 SYSCLK 计算。

48 MHz 路径参考此前已抓取仿真会话的 Keil 测试例程主时钟选择；这是待实板验证的排查方案。
要在 Debug 中恢复原时钟，可在 CMake 选项设置 `-DSTC_USB_ICE_SAFE_CLOCK=OFF` 后重新构建。
USB 模式变更后必须进入 USB-ISP 并运行 `stc_debug_enable`，下载新 Debug HEX，再启动调试。

离线模拟目标运行内置的 NOP / SJMP 测试代码，只用于验证客户端和服务端连接，
不执行板卡应用，也不模拟 GPIO / UART 等外设。

## 符号、变量与限制

调试目标 `stc_debug_build` 将同次链接的 `.cdb`、`.hex` 转成：

```text
build/Debug/firmware/STC32G144K246_32BIT_SDCC_Template.debug.elf
```

ELF 使用 MCS-251 大端布局，保留 SDCC 的 16 位 int 和 24 位指针 ABI。
转换时只在 `Core/Src`、`Drivers/Src`、`Hardware/Src` 中解析源文件，并将绝对路径写入行表。
新增源码目录时在 `cmake/stc-debug.cmake` 追加 `--source-dir`。
同名文件无法唯一匹配时转换报错，需要进一步明确源文件映射。

当前支持寄存器读取、内存访问、暂停、继续、单指令步进、软件断点、源码行和简单整型全局变量。
完整调用栈、局部变量、复杂类型、`next` / `finish` 尚未实现，硬件后端仍需上板验收。
调试 ELF 仅供符号读取，运行配置已关闭自动下载和自动复位。

2026-11-15 实板补充：USB-ICE V4.0 已通过服务端连接、GDB 寄存器读取和单指令步进。
已修正 HID 零超时读取阻塞、已暂停设备不回复重复暂停命令这两项启动问题。
全速继续测试后出现 USB-ICE 不再响应，完整的继续/暂停及软件断点流程尚未验收，
需要先恢复板卡的 ICE 通信再继续排查；完整记录位于 STCForge 的 `docs/validation.md`。

命令行执行同样的调试准备（SWD 模式会比较并同步代码页）：

```powershell
cmake --build build/Debug --target stc_debug_build
```

2026-11-15 的离线验收：STCForge 100 项测试通过；下载入口的离线回归完成，其中 3 项原有测试跳过；
模板下载入口的 8 项测试通过，覆盖普通下载、带选项下载和 ICE 切换的完整模拟 HID 流程。
另以抓包帧 21 的实际状态重建配置，与帧 1683 的 46 字节配置逐字节一致，
只有 MSR3 从 `F7` 变为 `77`。离线预览也使用相同字段和偏移，未枚举设备。
