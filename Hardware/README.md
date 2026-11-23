# STC32G144K246 开发板 BSP

本目录按用户提供的板卡接线实现，采用本工程的 SDCC MCS-251 和 large 模型。
正常系统时钟为 90 MHz；Debug 默认启用待实板复测的 USB-ICE 48 MHz 兼容排查配置，
详见 `Misc/STCFORGE_DEBUG.md`。HSIOCLK 单独选择 HPLL2/2（180 MHz），SPI2 按这一输入计算分频；
CPU、Timer1、UART7 与 IAP 参数统一按 `SYSCLK` 配置。
引脚配置以板卡接线为准；控制器操作查证官方手册及官方 DEMO，未使用基本为空的 BSP_Keil 配置。

## 默认例程

调用一次 `system_init()`，系统依次完成时钟、扩展寄存器访问、BSP基础引脚、UART7和Timer1初始化。
默认只启用下列资源：

| 资源 | 引脚 | 默认行为 |
| --- | --- | --- |
| LED | P9.3 | 高电平亮，上电灭；主循环每1000ms翻转 |
| 调试串口 UART7 | P9.0 RX / P9.1 TX | 115200、8N1、Timer7；上电问候、接收回显 |
| KEY | P3.2 | 暂按低电平有效，内部上拉；20ms消抖，按下打印 KEY pressed |

按键极性等板级选项集中在 `Inc/bsp_config.h`。只有LED高电平有效、双CAN不接STB是用户已明确的事实；KEY、RS485 DIR、背光、CTP复位/中断的默认极性均有注释，可按原理图修改。

## 完整接线

| 资源 | 本板信号与引脚 |
| --- | --- |
| USB | D− P3.0；D+ P3.1 |
| CAN1 | RX P3.6；TX P3.7；不接STB |
| CAN2 | RX PA.0；TX PA.1；不接STB |
| RS485 / UART4 | RX PA.2；TX PA.3；DIR2 PA.4 |
| RS485 / UART8 | RX PA.6；TX PA.7；DIR PA.5 |
| SD / SPI2 | SS PB.1；MOSI PB.2；MISO PB.3；SCLK PB.4 |
| I2C1（EEPROM+CTP共享） | SCL P7.7；SDA P7.6 |
| QSPI Flash | SCLK P7.1；IO0 P7.0；IO1 P7.2；IO2 P7.3；IO3 P7.4；NCS P7.5 |
| QSPI PSRAM | SCLK P4.3；IO0 P4.0；IO1 P4.1；IO2 P4.6；IO3 P4.7；NCS P5.4 |
| LCD8080 8bit | D0～D7 P2.0～P2.7；DC P4.5；RD P4.4；WR P4.2；CS PB.0 |
| LCD背光 | P9.2，可复用PWMF7；当前提供GPIO开关 |
| CTP | INT PB.7；RESET PB.6；通过I2C1通信 |
| KEY / LED / UART7 | 见默认例程表 |
| 外部32K晶振 | P1.6/P1.7，保留，不启用 |

## 模块边界与调用方式

`bsp_board_prepare(resource)`只设置引脚与复用，不自动启动USB/CAN控制器，也不产生总线事务。
一般由各总线的init内部调用；独立移植USB或CAN驱动时可自行调用此入口。直接调用前须已使能XFR访问，并确保对应控制器处于停止状态。

LED与按键分别使用 `bsp_led.h`、`bsp_key.h`。按键在主循环中传入 `system_millis()`调用 `bsp_key_poll()`，得到单次按下/释放事件；上电按住不产生虚假的按下事件，计时使用无符号差值处理回绕。

RS485、SPI2-SD、I2C1的接口和限制见各模块头文件。所有总线按需初始化，不在默认例程中同时开启。SD模块提供SPI传输层，EEPROM与CTP共用I2C传输层；器件地址、SD命令、文件系统、EEPROM分页与写完成轮询由器件驱动负责。

### LCD与触摸

`bsp_lcd_bus_init()`启用8位i8080硬件接口，时钟分频、建立时间与保持时间在配置头中集中设置。
提供写命令、批量写数据、批量读数据与读状态函数，片选由BSP管理；读取的dummy字节和显示像素字节顺序由面板驱动负责。
总线超时后关闭LCM、释放片选，重新调用init后恢复。没有面板型号，因此不发送ILI9341或其他假定型号的初始化序列，默认不亮背光。

`bsp_ctp_io_init()`单独准备触摸复位与中断引脚，`bsp_ctp_set_reset()`按“是否复位”的逻辑控制，不固定复位脉宽；`bsp_ctp_interrupt_active()`读取有效中断电平。触控芯片的地址选择、RESET/INT启动配合与寄存器协议由器件驱动负责。

### Flash与PSRAM共用QSPI

只有一个QSPI控制器，不可同时操作Flash与PSRAM，也不能用两个普通GPIO片选冒充两路QSPI。
使用 `bsp_qspi_acquire(device, config)`获取控制器：检查BUSY、FIFO与DMA，确认空闲后禁用控制器，保持两个NCS为高，切换整组引脚，再按本器件的分频、容量范围和时钟空闲电平配置。
完成后调用 `bsp_qspi_release(device)`。重复acquire或向另一个器件切换时若仍持有控制器，返回BUSY；不会主动中断正在运行的传输。

`bsp_qspi_transfer()`提供不含交替字节的SDR间接指令，支持单/双/四线指令、1～4字节地址和最多65535字节的数据，nCS由硬件控制。需要交替字节或DDR的器件命令不在此接口范围；不会自动设置QE位、切换QPI或发送擦除/复位指令。
读数据时边读FIFO边等待结束，避免数据超过32字节后卡在满FIFO。
超时/访问错误后请求中止并保留所有权；调用 `bsp_qspi_abort()`等待中止完成，再release。总线恢复不代表器件内部擦写已完成，器件忙状态仍需上层驱动检查。

PSRAM使用P4.7作IO3，因此选择PSRAM时会关闭P4.7的外部复位功能。P5.4与P1.2在该封装内共用焊盘，BSP令P1.2为高阻并采用P5.4原生功能映射。两组QSPI操作均保留I2C的P7.6/7与LCD的P4.2/4/5，不改动P1.6/7晶振脚。

### 双CAN与USB

本板双CAN均未连接STB。准备CAN1/CAN2引脚时显式将 `CANn_AUX_CR.STBYEN`清零，只配置RX/TX，复用表中的STB引脚不被CAN占用。尤其CAN2候选STB为P2.3，必须留给LCD数据总线。
本阶段提供CAN引脚准备，没有配置CAN位时序、收发FIFO、过滤器或中断；不能将“引脚已接入”当成“CAN通信已验证”。

USB入口只准备P3.0/P3.1物理引脚，没有移植USB设备协议栈和描述符，不会自动枚举CDC/HID。
芯片自带USB ISP与应用USB协议栈是两个独立功能，现有下载流程不依赖这个BSP入口。

## 调用约定

- 先完成 `system_init()`，再从主循环调用可阻塞的BSP总线函数，保持全局中断与Timer1时基开启。
- 不在ISR中调用这些总线函数；各总线按单调用者设计，没有RTOS互斥或可重入支持。
- `timeout_ms`表示整笔调用的时间预算，不为每个字节重新计时；错误状态通过 `bsp_status_t`返回。
- 共享端口按掩码修改；P9/PA/PB输出优先用SETB/CLRB寄存器，避免覆盖同口的其他资源。
- DMA不由本阶段BSP接管。对应DMA启用时，总线接口会拒绝接管；不要与直接写外设寄存器的代码交叉使用。

## 验证

Debug 和 Release 采用两个 CMake 预设构建，链接后自动检查固件布局。BSP 的寄存器模拟测试不覆盖电气特性或完整器件协议，上板时应按资源逐项验证。
