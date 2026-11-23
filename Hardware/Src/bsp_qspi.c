#include "bsp_qspi.h"
#include "bsp_gpio.h"
#include "bsp_board.h"
#include "system_stc32.h"

static bsp_qspi_device_t owner;
static uint8_t transfer_failed;

static uint8_t qspi_idle(void)
{
    return !QSPI_CheckBusy() && !QSPI_CheckFIFOLevel() &&
        !(DMA_QSPI_CR & (DMAQSPICR_ENQSPI_MSK | DMAQSPICR_TRIGW_MSK | DMAQSPICR_TRIGR_MSK));
}

static void qspi_park(void)
{
    /* 调用时QSPI必须已禁用。两个CS先保持高，未选器件的数据脚保持高阻。
     * P7.6/7 (I2C)、P4.2/4/5 (LCD)完全不动。 */
    SetP7nInitLevelHigh(PIN_5);
    SetP5nInitLevelHigh(PIN_4);
    BSP_GPIO_OUTPUT(7, PIN_5);
    BSP_GPIO_OUTPUT(5, PIN_4);
    BSP_GPIO_INPUT(7, PIN_0 | PIN_1 | PIN_2 | PIN_3 | PIN_4, 1);
    BSP_GPIO_INPUT(4, PIN_0 | PIN_1 | PIN_3 | PIN_6 | PIN_7, 1);
}

bsp_status_t bsp_qspi_acquire(bsp_qspi_device_t device, const bsp_qspi_config_t *config)
{
    if ((device != BSP_QSPI_FLASH && device != BSP_QSPI_PSRAM) || !config ||
        !config->size_bits || config->size_bits > 32 || config->clock_high > 1)
        return BSP_ERROR_ARGUMENT;
    if (!system_is_ready()) return BSP_ERROR_NOT_READY;
    if (owner != BSP_QSPI_NONE || !qspi_idle()) return BSP_ERROR_BUSY;
    QSPI_Disable();
    qspi_park();
    if (device == BSP_QSPI_FLASH) {
        if (config->clock_high) { SetP7nInitLevelHigh(PIN_1); }
        else { SetP7nInitLevelLow(PIN_1); }
        BSP_GPIO_OUTPUT(7, PIN_1);
        SetP7nAutoMode(PIN_0 | PIN_2 | PIN_3 | PIN_4);
        SetP7nSlewRateFast(PIN_0 | PIN_1 | PIN_2 | PIN_3 | PIN_4 | PIN_5);
        QSPI_SwitchP7n();
    } else {
        /* 封装将P1.2与P5.4共同接至外部P5.4，先令P1.2高阻，避免内部GPIO争用。
         * 保持P5.4的原生数字功能映射（手册14.1.10）。 */
        BSP_GPIO_INPUT(1, PIN_2, 0);
        CLR_REG_BIT(P_SWX1, BIT0);
        RST_ResetPinAsGPIO(); /* 用户将P4.7明确接作PSRAM IO3。 */
        if (config->clock_high) { SetP4nInitLevelHigh(PIN_3); }
        else { SetP4nInitLevelLow(PIN_3); }
        BSP_GPIO_OUTPUT(4, PIN_3);
        SetP4nAutoMode(PIN_0 | PIN_1 | PIN_6 | PIN_7);
        SetP4nSlewRateFast(PIN_0 | PIN_1 | PIN_3 | PIN_6 | PIN_7);
        SetP5nSlewRateFast(PIN_4);
        QSPI_SwitchP4n();
    }
    /* 不使用官方示例对CR1保留B4的SSHIFT写入，按手册定义设置。 */
    QSPI_CR1 = 0;
    QSPI_CR3 = 0; /* 轮询，不启用QSPI中断或自动轮询。 */
    QSPI_SetClockDivider(config->prescaler);
    QSPI_SetFlashSize(config->size_bits - 1U);
    QSPI_SetCSHold(1);
    if (config->clock_high) { QSPI_SetSCKNormalHigh(); }
    else { QSPI_SetSCKNormalLow(); }
    QSPI_SetFIFOLevel(0);
    QSPI_InstructionAlways();
    QSPI_ClearTimeout();
    QSPI_ClearMatch();
    QSPI_ClearTransfer();
    QSPI_ClearError();
    transfer_failed = 0;
    owner = device;
    QSPI_Enable();
    return BSP_OK;
}

bsp_status_t bsp_qspi_release(bsp_qspi_device_t device)
{
    if (device == BSP_QSPI_NONE || owner != device) return BSP_ERROR_ARGUMENT;
    if (!qspi_idle() || (QSPI_CR1 & QSPICR1_ABORT_MSK)) return BSP_ERROR_BUSY;
    QSPI_Disable();
    qspi_park();
    owner = BSP_QSPI_NONE;
    return BSP_OK;
}

bsp_qspi_device_t bsp_qspi_owner(void)
{
    return owner;
}

static bsp_status_t qspi_check(uint32_t start_ms, uint32_t timeout_ms)
{
    if (QSPI_CheckError()) return BSP_ERROR_IO;
    if ((uint32_t)(system_millis() - start_ms) >= timeout_ms) return BSP_ERROR_TIMEOUT;
    return BSP_OK;
}

bsp_status_t bsp_qspi_transfer(bsp_qspi_device_t device, const bsp_qspi_command_t *command,
                               const uint8_t *tx, uint8_t *rx, uint16_t length,
                               uint32_t timeout_ms)
{
    uint32_t start_ms;
    uint16_t remaining = length;
    bsp_status_t result;
    if (!command || !command->instruction_mode || command->instruction_mode > 3 ||
        command->address_mode > 3 || command->data_mode > 3 || command->dummy_cycles > 31 ||
        (command->address_mode && (!command->address_bytes || command->address_bytes > 4)) ||
        (!command->address_mode && command->address_bytes) ||
        (length && (!command->data_mode || (!tx && !rx) || (tx && rx))) ||
        (!length && (command->data_mode || tx || rx)) ||
        (rx && command->data_mode > 1 && !command->dummy_cycles)) return BSP_ERROR_ARGUMENT;
    if (command->address_mode && command->address_bytes < 4 &&
        (command->address >> (8U * command->address_bytes))) return BSP_ERROR_ARGUMENT;
    if (device == BSP_QSPI_NONE || owner != device || transfer_failed) return BSP_ERROR_NOT_READY;
    if (!bsp_timebase_ready()) return BSP_ERROR_NOT_READY;
    if (!qspi_idle()) return BSP_ERROR_BUSY;
    if (!timeout_ms) return BSP_ERROR_TIMEOUT;
    QSPI_ClearTransfer();
    QSPI_ClearError();
    QSPI_SetInstructionMode(command->instruction_mode);
    QSPI_SetAddressMode(command->address_mode);
    if (command->address_mode) { QSPI_SetAddressSize(command->address_bytes - 1U); }
    QSPI_NoAlternate();
    QSPI_SetDummyCycles(command->dummy_cycles);
    QSPI_SetDataMode(command->data_mode);
    if (length) { QSPI_SetDataLength(length - 1U); }
    if (rx) { QSPI_SetReadMode(); }
    else { QSPI_SetWriteMode(); }
    start_ms = system_millis();
    QSPI_SetInstruction(command->instruction);
    /* AR必须高字节先写，AR1最后写才触发地址阶段。 */
    if (command->address_mode) { QSPI_SetAddress(command->address); }
    while (remaining) {
        if (rx && QSPI_CheckFIFOLevel()) {
            *rx++ = QSPI_ReadData();
            --remaining;
        } else if (tx && QSPI_CheckFIFOLevel() < 32U) {
            QSPI_WriteData(*tx++);
            --remaining;
        }
        result = qspi_check(start_ms, timeout_ms);
        if (result != BSP_OK) goto failed;
    }
    /* 读操作不能先等TCF再读FIFO，否则长度>32时会一直被满FIFO阻塞。 */
    while (!QSPI_CheckTransfer() || QSPI_CheckBusy()) {
        result = qspi_check(start_ms, timeout_ms);
        if (result != BSP_OK) goto failed;
    }
    QSPI_ClearTransfer();
    return BSP_OK;
failed:
    QSPI_Abort();
    transfer_failed = 1;
    return result;
}

bsp_status_t bsp_qspi_abort(bsp_qspi_device_t device, uint32_t timeout_ms)
{
    uint32_t start_ms;
    if (device == BSP_QSPI_NONE || owner != device) return BSP_ERROR_ARGUMENT;
    if (!bsp_timebase_ready()) return BSP_ERROR_NOT_READY;
    if (DMA_QSPI_CR & (DMAQSPICR_ENQSPI_MSK | DMAQSPICR_TRIGW_MSK | DMAQSPICR_TRIGR_MSK))
        return BSP_ERROR_BUSY;
    start_ms = system_millis();
    QSPI_Abort();
    transfer_failed = 1;
    while (!qspi_idle() || (QSPI_CR1 & QSPICR1_ABORT_MSK)) {
        if ((uint32_t)(system_millis() - start_ms) >= timeout_ms) return BSP_ERROR_TIMEOUT;
    }
    QSPI_ClearTransfer();
    QSPI_ClearError();
    transfer_failed = 0;
    return BSP_OK;
}
