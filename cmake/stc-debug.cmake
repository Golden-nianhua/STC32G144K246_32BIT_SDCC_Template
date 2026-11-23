# 只为 Debug 构建生成调试符号；保留原来的两个 CMake 预设。
# 本机路径与连接参数在 Misc/stcforge.toml 中维护。
set(stcforge_config "${CMAKE_SOURCE_DIR}/Misc/stcforge.toml")
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${stcforge_config}")
if(NOT STCFORGE_EXECUTABLE)
    message(STATUS "未找到 stcforge：仍可构建；设置 STCFORGE_BIN 后可调试")
    return()
endif()
set(stcforge_command "${STCFORGE_EXECUTABLE}" clion --config "${stcforge_config}")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_custom_target(stc_debug_build
        COMMAND ${stcforge_command} prepare --image "${firmware_image}"
            --output "${firmware_stem}.debug.elf"
            --root "${CMAKE_SOURCE_DIR}" --source-dir Core/Src
            --source-dir Drivers/Src --source-dir Hardware/Src
        DEPENDS ${CMAKE_PROJECT_NAME}
        BYPRODUCTS "${CMAKE_BINARY_DIR}/firmware/${CMAKE_PROJECT_NAME}.debug.elf"
        COMMENT "生成调试符号，按所选方式准备调试"
        USES_TERMINAL
        VERBATIM)
    set_target_properties(stc_debug_build PROPERTIES FOLDER "tools")
    # 制作仿真芯片可能擦除程序区，必须显式运行，不能挂到 Debug 启动前。
    stc_add_clion_configuration(stc_debug_enable "${CMAKE_PROJECT_NAME}" tools
        "${STCFORGE_EXECUTABLE}"
        "clion --config &quot;${stcforge_config}&quot; enable --isp &quot;${STC_ISP_EXECUTABLE}&quot; --image &quot;$CMakeCurrentProductFile$&quot; --debug-firmware-dir &quot;${CMAKE_BINARY_DIR}/firmware&quot;"
        TRUE)
    execute_process(COMMAND ${stcforge_command} configure
        --project-name "${CMAKE_PROJECT_NAME}" --root "${CMAKE_SOURCE_DIR}"
        --image "${CMAKE_BINARY_DIR}/firmware/${CMAKE_PROJECT_NAME}.hex" --preset STC32G144K246-Debug
        --toolchain MCS-251 --launcher "${STCFORGE_EXECUTABLE}" --isp "${STC_ISP_EXECUTABLE}"
        RESULT_VARIABLE stcforge_result)
    if(NOT stcforge_result STREQUAL "0")
        message(FATAL_ERROR "STCForge 运行配置生成失败，请检查 Misc/stcforge.toml")
    endif()
endif()
# Release 并行配置时也保留由 Debug 生成的两个入口。
set_property(GLOBAL APPEND PROPERTY STC_CLION_RUN_CONFIGS
    "${run_dir}/STC32_Auto_STCForge_debug.xml"
    "${run_dir}/STC32_Auto_stc_debug_enable.xml")
