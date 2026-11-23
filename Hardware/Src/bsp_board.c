#include "bsp_board.h"
#include "bsp_config.h"
#include "bsp_gpio.h"
#include "bsp_key.h"
#include "bsp_led.h"
#include "system_stc32.h"

uint8_t bsp_timebase_ready(void)
{
    return system_is_ready() && EA && TR1 && ET1;
}

void bsp_board_init(void)
{
    bsp_led_init();
    bsp_key_init();
    (void)bsp_board_prepare(BSP_RESOURCE_UART7);
}

bsp_status_t bsp_board_prepare(bsp_resource_t resource)
{
    switch (resource) {
    case BSP_RESOURCE_UART7:
        P9SETB = PIN_1;
        BSP_GPIO_INPUT(9, PIN_0, 1);
        BSP_GPIO_OUTPUT(9, PIN_1);
        UART7_SwitchP9091();
        break;
    case BSP_RESOURCE_RS485_UART4:
        PASETB = PIN_3;
#if BSP_RS485_TX_HIGH
        PACLRB = PIN_4;
#else
        PASETB = PIN_4;
#endif
        BSP_GPIO_INPUT(A, PIN_2, 1);
        BSP_GPIO_OUTPUT(A, PIN_3 | PIN_4);
        UART4_SwitchPA2A3();
        break;
    case BSP_RESOURCE_RS485_UART8:
        PASETB = PIN_7;
#if BSP_RS485_TX_HIGH
        PACLRB = PIN_5;
#else
        PASETB = PIN_5;
#endif
        BSP_GPIO_INPUT(A, PIN_6, 1);
        BSP_GPIO_OUTPUT(A, PIN_5 | PIN_7);
        UART8_SwitchPA6A7();
        break;
    case BSP_RESOURCE_SPI2_SD:
        PBSETB = PIN_1 | PIN_2; /* 软件片选释放，MOSI=1。 */
        PBCLRB = PIN_4;        /* SD SPI mode0，CLK 空闲低。 */
        BSP_GPIO_OUTPUT(B, PIN_1 | PIN_2 | PIN_4);
        BSP_GPIO_INPUT(B, PIN_3, 1);
        SPI2_SwitchPBn();
        break;
    case BSP_RESOURCE_I2C1:
        SetP7nInitLevelHigh(PIN_6 | PIN_7);
        BSP_GPIO_COMMON(7, PIN_6 | PIN_7);
        SetP7nOpenDrainMode(PIN_6 | PIN_7);
        EnableP7nPullUp(PIN_6 | PIN_7);
        SetP7nAutoMode(PIN_6 | PIN_7);
        I2C1_SwitchP7677();
        break;
    case BSP_RESOURCE_LCD8080:
        /* LCD 控制器的具体时序由 bsp_lcd_bus_init 设置，先保持总线空闲。 */
        PBSETB = PIN_0;
#if BSP_LCD_BACKLIGHT_HIGH
        P9CLRB = PIN_2;
#else
        P9SETB = PIN_2;
#endif
        SetP4nInitLevelHigh(PIN_2 | PIN_4);
        SetP4nInitLevelLow(PIN_5);
        SetP2nInitLevelHigh(PIN_ALL);
        BSP_GPIO_OUTPUT(B, PIN_0);
        BSP_GPIO_OUTPUT(9, PIN_2);
        BSP_GPIO_OUTPUT(4, PIN_2 | PIN_4 | PIN_5);
        BSP_GPIO_COMMON(2, PIN_ALL);
        SetP2nHighZInputMode(PIN_ALL);
        SetP2nAutoMode(PIN_ALL); /* LCM 读写时自动切换数据方向。 */
        LCM_DATA8BSwitchP2();
        LCM_RSSwitchP45();
        LCM_CTRLSwitchP4442();
        break;
    case BSP_RESOURCE_CTP:
#if BSP_CTP_RESET_LOW
        PBSETB = PIN_6;
#else
        PBCLRB = PIN_6;
#endif
        BSP_GPIO_OUTPUT(B, PIN_6);
        BSP_GPIO_INPUT(B, PIN_7, BSP_CTP_IRQ_LOW);
        break;
    case BSP_RESOURCE_CAN1:
        CAN1_DisableStandbyPin(); /* 本板未连接STB，路由中的P1.2保持其他用途。 */
        SetP3nInitLevelHigh(PIN_7); /* CAN TX 空闲为隐性电平。 */
        BSP_GPIO_INPUT(3, PIN_6, 1);
        BSP_GPIO_OUTPUT(3, PIN_7);
        CAN1_SwitchP363712();
        break;
    case BSP_RESOURCE_CAN2:
        CAN2_DisableStandbyPin(); /* 本板未连接STB，不占用路由中的P2.3/LCD数据脚。 */
        PASETB = PIN_1;
        BSP_GPIO_INPUT(A, PIN_0, 1);
        BSP_GPIO_OUTPUT(A, PIN_1);
        CAN2_SwitchPA0A123();
        break;
    case BSP_RESOURCE_USB:
        /* D-/D+ 交给 USB 模块，不用 GPIO 模拟拉高、不启用片内上拉。
         * 这里只准备物理引脚；USB 类、描述符和 PHY 启动由 USB 栈负责。 */
        BSP_GPIO_COMMON(3, PIN_0 | PIN_1);
        SetP3nHighZInputMode(PIN_0 | PIN_1);
        SetP3nAnalogInput(PIN_0 | PIN_1);
        SetP3nAutoMode(PIN_0 | PIN_1);
        break;
    default:
        return BSP_ERROR_ARGUMENT;
    }
    return BSP_OK;
}
