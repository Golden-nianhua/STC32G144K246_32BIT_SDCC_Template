# 与 STC89 模板保持 App / tools 分组：固件运行前构建，工具按需直接执行。
# CLion 并行配置 Debug/Release 时，串行更新共享 XML。
set(run_dir "${CMAKE_SOURCE_DIR}/.idea/runConfigurations")
file(MAKE_DIRECTORY "${run_dir}")
file(LOCK "${CMAKE_SOURCE_DIR}/.idea/STC32_Auto_RunConfigs.lock" GUARD PROCESS TIMEOUT 60)

# 下载参数只在执行时从工程的 TOML 读取。
set(stc_isp_config "${CMAKE_SOURCE_DIR}/Misc/stc-isp.toml")
if(STCFORGE_BIN)
    find_program(stc_isp_program NAMES stc-isp PATHS "${STCFORGE_BIN}" NO_DEFAULT_PATH NO_CACHE)
    find_program(stcforge_program NAMES stcforge PATHS "${STCFORGE_BIN}" NO_DEFAULT_PATH NO_CACHE)
    if(NOT stc_isp_program OR NOT stcforge_program)
        message(FATAL_ERROR "STCFORGE_BIN 中缺少 stc-isp 或 stcforge：${STCFORGE_BIN}")
    endif()
else()
    find_program(stc_isp_program NAMES stc-isp NO_CACHE)
    find_program(stcforge_program NAMES stcforge NO_CACHE)
endif()
if(NOT stc_isp_program)
    set(stc_isp_program "stc-isp")
endif()
set(STC_ISP_EXECUTABLE "${stc_isp_program}")
set(STCFORGE_EXECUTABLE "${stcforge_program}")
set(stc_isp_command "${STC_ISP_EXECUTABLE}" --config "${stc_isp_config}")

add_custom_target(stc_info
    COMMAND ${stc_isp_command} --info
    COMMENT "读取芯片型号和当前硬件配置" USES_TERMINAL VERBATIM)
set_target_properties(stc_info PROPERTIES FOLDER "tools")

# 普通 ISP 下载由下面两个共享运行配置执行。它们在运行前构建固件，
# 避免再为同一操作创建 stc_flash* 自定义目标，造成 CLion 入口重复。

function(stc_add_clion_configuration run_name build_target folder executable parameters build_before_run)
    set(CLION_RUN_TARGET "${run_name}")
    set(CLION_BUILD_TARGET "${build_target}")
    set(CLION_TARGET_FOLDER "${folder}")
    set(CLION_RUN_EXECUTABLE "${executable}")
    set(CLION_RUN_PARAMETERS "${parameters}")
    if(build_before_run)
        set(template clion-custom-target-run.xml.in)
    else()
        set(template clion-tool-run.xml.in)
    endif()
    set(run_file "${run_dir}/STC32_Auto_${run_name}.xml")
    configure_file("${CMAKE_SOURCE_DIR}/cmake/${template}" "${run_file}" @ONLY NEWLINE_STYLE CRLF)
    set_property(GLOBAL APPEND PROPERTY STC_CLION_RUN_CONFIGS "${run_file}")
endfunction()

stc_add_clion_configuration("${CMAKE_PROJECT_NAME}" "${CMAKE_PROJECT_NAME}" App
    "${CMAKE_COMMAND}" "-E true" TRUE)
# 先构建固件，然后把所选 Debug/Release 的产品路径传给 stc-isp。
stc_add_clion_configuration("${CMAKE_PROJECT_NAME}_flash" "${CMAKE_PROJECT_NAME}" App
    "${STC_ISP_EXECUTABLE}" "--config &quot;${stc_isp_config}&quot; --image &quot;$CMakeCurrentProductFile$&quot; --option modify_hardware_options=false --option usb_ice_enabled=false" TRUE)
stc_add_clion_configuration("${CMAKE_PROJECT_NAME}_flash_with_options" "${CMAKE_PROJECT_NAME}" App
    "${STC_ISP_EXECUTABLE}" "--config &quot;${stc_isp_config}&quot; --image &quot;$CMakeCurrentProductFile$&quot; --option usb_ice_enabled=false" TRUE)
stc_add_clion_configuration(stc_info stc_info tools "${STC_ISP_EXECUTABLE}"
    "--config &quot;${stc_isp_config}&quot; --info" FALSE)

include("${CMAKE_CURRENT_LIST_DIR}/stc-debug.cmake")

# 只清理本工程自动生成、已经移除的运行配置。
get_property(expected_run_configs GLOBAL PROPERTY STC_CLION_RUN_CONFIGS)
file(GLOB existing_run_configs "${run_dir}/STC32_Auto_*.xml")
foreach(existing IN LISTS existing_run_configs)
    if(NOT existing IN_LIST expected_run_configs)
        file(REMOVE "${existing}")
    endif()
endforeach()
