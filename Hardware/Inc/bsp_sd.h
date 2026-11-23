#ifndef BSP_SD_H
#define BSP_SD_H

#include <stdint.h>
#include "bsp_common.h"

/* SPI2 仅提供 SD 卡字节传输层，不包含 SD 命令、初始化和 FAT 驱动。
 * PB.1 为软件 CS，PB.2 MOSI，PB.3 MISO，PB.4 SCLK。
 * 硬件 SPI2 默认使用软件 CS + Mode3（CPOL=1、CPHA=1）、MSB 先行；该组合
 * 是手册明确支持的 SSIG=1 配置，但仅适用于经确认支持 SPI Mode3 的卡。
 * 若卡只支持 Mode0，请改用 bsp_sd_init_gpio_mode0() 的 GPIO 低速后备。 */

/* SPI2 工作时钟为 HSIOCLK=BOARD_HSIO_HZ=180 MHz，不是 SYSCLK=90 MHz。
 * 满足 SD 上电 <=400 kHz 的最小预分频为 113
 * （180 MHz/113/4≈398.2 kHz）。init 会拒绝产生更高 SCLK 的分频。 */
#define BSP_SD_DEFAULT_CLKDIV 113U

/* 设置 SPI2_CLKDIV 1..255，SP2R=0（SCLK2=SPI2 工作时钟/4）。
 * 本工程按 HSIOCLK=BOARD_HSIO_HZ=180 MHz 校验，要求 SCLK2<=400 kHz；
 * 113 对应约 398.2 kHz，不能使用会超过 400 kHz 的 112 或更小值。 */
bsp_status_t bsp_sd_init(uint8_t spi2_clkdiv);

/* 选择固定四档 SP2R 分频：4、8、16 或 2；其中 2 档会启用高速 SPI2。
 * 实际 SCLK2 还受 SPI2_CLKDIV 预分频影响；本函数固定使用 113。
 * SD 上电初始化建议使用 bsp_sd_init()；本函数用于卡初始化后的提速。 */
bsp_status_t bsp_sd_init_divider(uint8_t divider);

/* GPIO 软件位操作后备：Mode0、MSB 先行，速率保守低于 400 kHz。
 * 仍使用 PB.1 软件 CS；初始化后 bsp_sd_transfer() 自动走 GPIO 后端。
 * 仅用于不支持 Mode3 的卡，不保证精确的 SPI 时钟频率。 */
bsp_status_t bsp_sd_init_gpio_mode0(void);

/* 未初始化、参数错误、总线忙或超时时返回相应错误。
 * count 为 0 时直接返回 BSP_OK，不访问 SPI2DAT；tx 为 NULL 时发 0xFF；
 * rx为NULL时丢弃接收数据。硬件超时后关闭SPI2、释放CS并标记未就绪，
 * 须重新init；GPIO后备超时时保持CLK空闲低，CS由调用者释放。 */
bsp_status_t bsp_sd_transfer(const uint8_t *tx, uint8_t *rx, uint16_t count,
                             uint32_t timeout_ms);

/* 软件片选：PB.1 低有效，位写，不修改同端口 LCD 引脚。 */
void bsp_sd_cs_select(void);
void bsp_sd_cs_deselect(void);

#endif
