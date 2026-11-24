cmake_minimum_required(VERSION 3.21)

# 工具路径：Debug 和 Release 共用。按本机安装位置修改。
set(SDCC_BIN "D:/Code/c-env/SDCC/SDCC-4.6.0-MCS251/bin")
# 仅在 MCS-251 包的归档工具不能运行时指定备用目录，否则留空。
set(SDCC_ARCHIVE_BIN "D:/Code/c-env/SDCC/SDCC-4.6.0/bin")
# 填 STCForge 的 bin 目录；留空则从 PATH 查找。
set(STCFORGE_BIN "D:/Projects/stcforge/dist/windows")
# uv 已在 PATH 中时可以留空。
set(UV_EXECUTABLE "D:/Code/uv/uv.exe")

# 目录名按现有路径保留；固件、目标和预设使用芯片的实际型号。
set(CMAKE_PROJECT_NAME STC32G144K246_32BIT_SDCC_Template)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND NOT DEFINED CMAKE_SYSTEM_NAME)
    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdcc-mcs251-toolchain.cmake")
endif()
project(${CMAKE_PROJECT_NAME} LANGUAGES C ASM)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# SDCC 不直接接受 GCC 的 -MF/-MT，需经 -Wp 转发给 sdcpp。
# 让 Ninja 正确跟踪头文件修改，包括 main 所在单元的中断声明。
set(CMAKE_DEPFILE_FLAGS_C "-Wp-MMD,-MF,<DEP_FILE>,-MT,<DEP_TARGET>")
set(CMAKE_C_DEPFILE_FORMAT gcc)
set(CMAKE_C_DEPENDS_USE_COMPILER TRUE)

if(NOT CMAKE_C_COMPILER_ID STREQUAL "SDCC")
    message(FATAL_ERROR "请选择支持 -mmcs251 的 SDCC 工具链")
endif()
execute_process(COMMAND "${CMAKE_C_COMPILER}" --version
    OUTPUT_VARIABLE sdcc_version ERROR_VARIABLE sdcc_version_error)
if(NOT "${sdcc_version}${sdcc_version_error}" MATCHES "mcs251")
    message(FATAL_ERROR "当前 SDCC 不包含 MCS-251 后端，请检查 SDCC_BIN")
endif()

if(NOT UV_EXECUTABLE)
    find_program(uv_program NAMES uv NO_CACHE REQUIRED)
    set(UV_EXECUTABLE "${uv_program}")
endif()
set(STC_PYTHON "${UV_EXECUTABLE}" run --script)

# 默认固件只使用 FF:0000..FF:FFFF；低地址扩展区的可用范围取决于 ISP 的 EEPROM 分区。
# HOME 从复位地址开始，GSINIT0 和其余程序段由链接器顺序排放。
set(STC_EDATA_SIZE 0x4000)
set(STC_XRAM_BASE 0x010000)
set(STC_XRAM_SIZE 0x20000)
# 低 256 字节留给寄存器银行、位变量和 near 数据；SPX 使用余下 edata。
set(STC_STACK_BASE 0x0100)

add_executable(${CMAKE_PROJECT_NAME}
    Core/Src/main.c
    Core/Src/system_stc32.c
    Core/Src/idle.asm
    Core/Src/startup.asm
    Drivers/Src/stc32_gpio.c
    Drivers/Src/stc32_uart7.c
    Hardware/Src/bsp_board.c
    Hardware/Src/bsp_led.c
    Hardware/Src/bsp_key.c
    Hardware/Src/bsp_lcd.c
    Hardware/Src/bsp_qspi.c
    Hardware/Src/bsp_rs485.c
    Hardware/Src/bsp_sd.c
    Hardware/Src/bsp_i2c.c
)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/firmware" FOLDER "App"
    C_COMPILER_LAUNCHER "${CMAKE_COMMAND};-P;${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdcc-compile.cmake;--")
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE Core/Inc Drivers/Inc Hardware/Inc)

# USB-ICE V4.0 在现有 90 MHz 时钟切换附近失联，先提供与 Keil 测试例程
# 一致的 IRC48M 调试主频。此兼容方案待实板复测，Release 仍使用 90 MHz。
option(STC_USB_ICE_SAFE_CLOCK "Debug 使用 IRC48M 48 MHz 排查 USB-ICE 时钟兼容性" ON)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    $<$<AND:$<BOOL:${STC_USB_ICE_SAFE_CLOCK}>,$<CONFIG:Debug>>:STC_USB_ICE_DEBUG=1>
    $<$<CONFIG:Debug>:STC_DEBUG_WATCH_DEMO=1>)

# 编译和链接必须采用相同模型、栈约定和配套运行库。
# large：普通变量使用 24 位 XRAM；stack-auto：自动变量使用 16 位 SPX。
set(SDCC_MCS251_ABI_OPTIONS --model-large --stack-auto --int-long-reent)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
    $<$<COMPILE_LANGUAGE:C>:${SDCC_MCS251_ABI_OPTIONS}>
    $<$<COMPILE_LANGUAGE:C>:--std-c11>
    $<$<AND:$<COMPILE_LANGUAGE:C>,$<CONFIG:Debug>>:--debug>
    $<$<AND:$<COMPILE_LANGUAGE:C>,$<CONFIG:Release>>:--opt-code-size>
)
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE
    ${SDCC_MCS251_ABI_OPTIONS}
    "SHELL:--code-loc 0xFF0000"
    "SHELL:--iram-size ${STC_EDATA_SIZE}"
    "SHELL:--xram-loc ${STC_XRAM_BASE}"
    "SHELL:--xram-size ${STC_XRAM_SIZE}"
    # 此版 sdld 的 SSEG 分配器仍限制在 256 字节内，只保留启动占位。
    # startup.asm 在 GSINIT1、任何 C 调用之前将 SPX 转移到 0x00FF。
    "SHELL:--stack-size 1"
    $<$<CONFIG:Debug>:--debug>
    $<$<CONFIG:Release>:--opt-code-size>
)

set(firmware_image "$<TARGET_FILE:${CMAKE_PROJECT_NAME}>")
set(firmware_stem "$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/$<TARGET_FILE_BASE_NAME:${CMAKE_PROJECT_NAME}>")
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${STC_PYTHON} "${CMAKE_SOURCE_DIR}/tools/build/firmware.py"
        --image "${firmware_image}" --map "${firmware_stem}.map"
        --bin "${firmware_stem}.bin" --packihx "${SDCC_PACKIHX}"
    COMMENT "生成 HEX/BIN，检查 MCS-251 内存布局并统计容量"
    VERBATIM
)
# 修改布局校验脚本后，下一次构建也应重新执行链接后检查。
set_property(TARGET ${CMAKE_PROJECT_NAME} APPEND PROPERTY LINK_DEPENDS
    "${CMAKE_SOURCE_DIR}/tools/build/firmware.py")
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES ADDITIONAL_CLEAN_FILES
    "${CMAKE_BINARY_DIR}/firmware/${CMAKE_PROJECT_NAME}.hex;${CMAKE_BINARY_DIR}/firmware/${CMAKE_PROJECT_NAME}.bin;${CMAKE_BINARY_DIR}/firmware/${CMAKE_PROJECT_NAME}.lk;${CMAKE_BINARY_DIR}/firmware/${CMAKE_PROJECT_NAME}.map;${CMAKE_BINARY_DIR}/firmware/${CMAKE_PROJECT_NAME}.mem")
include(cmake/stc-targets.cmake)
