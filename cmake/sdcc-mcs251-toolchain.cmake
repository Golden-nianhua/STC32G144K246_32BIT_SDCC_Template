# 需要包含 MCS-251 后端的 SDCC 分支，原版 SDCC 无法使用本工程。
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR mcs251)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/Modules")
if(NOT SDCC_BIN)
    message(FATAL_ERROR "请在根目录 CMakeLists.txt 中设置 SDCC_BIN（MCS-251 的 bin 目录）")
endif()
set(archive_bin "${SDCC_ARCHIVE_BIN}")
if(NOT archive_bin)
    set(archive_bin "${SDCC_BIN}")
endif()
if(CMAKE_HOST_WIN32)
    set(tool_suffix ".exe")
endif()

function(sdcc_require_tool variable directory executable)
    set(tool "${directory}/${executable}${tool_suffix}")
    if(NOT EXISTS "${tool}")
        message(FATAL_ERROR "未找到工具：${tool}，请检查 SDCC_BIN 或 SDCC_ARCHIVE_BIN")
    endif()
    set(${variable} "${tool}" CACHE FILEPATH "${executable}" FORCE)
endfunction()

sdcc_require_tool(CMAKE_C_COMPILER "${SDCC_BIN}" sdcc)
sdcc_require_tool(CMAKE_ASM_COMPILER "${SDCC_BIN}" sdas251)
sdcc_require_tool(SDCC_PACKIHX "${SDCC_BIN}" packihx)
sdcc_require_tool(CMAKE_AR "${archive_bin}" sdar)
sdcc_require_tool(CMAKE_RANLIB "${archive_bin}" sdranlib)
sdcc_require_tool(CMAKE_NM "${archive_bin}" sdnm)
sdcc_require_tool(CMAKE_OBJCOPY "${archive_bin}" sdobjcopy)

# CMake 的 Generic-SDCC-C 模块会用 SDCCAR_EXECUTABLE 覆盖 CMAKE_AR。
set(SDCCAR_EXECUTABLE "${CMAKE_AR}" CACHE FILEPATH "SDCC 归档器" FORCE)
list(APPEND CMAKE_TRY_COMPILE_PLATFORM_VARIABLES SDCC_BIN SDCC_ARCHIVE_BIN)

# 编译器探测也必须使用 MCS-251，不能让 CMake 先以默认 MCS-51 探测。
set(CMAKE_C_FLAGS_INIT "-mmcs251")
set(CMAKE_ASM_COMPILER_ID SDAS251)
