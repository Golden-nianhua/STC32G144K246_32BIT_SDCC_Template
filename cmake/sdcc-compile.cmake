cmake_minimum_required(VERSION 3.21)

# Invocation: cmake -P sdcc-compile.cmake -- <sdcc> <args...>
math(EXPR last_arg "${CMAKE_ARGC} - 1")
foreach(index RANGE 4 ${last_arg})
    string(REPLACE ";" "\\;" arg "${CMAKE_ARGV${index}}")
    list(APPEND compiler_command "${arg}")
endforeach()

execute_process(COMMAND ${compiler_command}
    ERROR_VARIABLE diagnostics RESULT_VARIABLE status)

# SDCC supplies target definitions for two macros already built into sdcpp.
set(macro_warning "<command-line>: warning: \"(__has_builtin|__STDC_HOSTED__)\" redefined")
set(previous_definition "<built-in>: note: this is the location of the previous definition")
set(noise "DPTR no-match:[^\n]*|${macro_warning}(\n${previous_definition})?")
string(REGEX REPLACE "(^|\n)((${noise})(\n|$))+" "\\1" diagnostics "${diagnostics}")
if(NOT diagnostics STREQUAL "")
    string(REGEX REPLACE "\n$" "" diagnostics "${diagnostics}")
    message("${diagnostics}")
endif()
if(NOT status STREQUAL "0")
    message(FATAL_ERROR "SDCC compilation failed (${status})")
endif()
