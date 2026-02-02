if(NOT DEFINED ARCHITECTURE)
    message(FATAL_ERROR "ARCHITECTURE is not defined")
endif()

set(COMPILE_OPTIONS_GNU -Wall -Werror -Wextra -Wpedantic -ffreestanding)

if(NOT DEFINED COMPILE_OPTIONS_${CMAKE_C_COMPILER_ID})
    message(FATAL_ERROR "${CMAKE_C_COMPILER_ID} is not supported")
endif()

set(COMPILE_OPTIONS_GNU_cortex_m33 -mcpu=cortex-m33)

if(NOT DEFINED COMPILE_OPTIONS_${CMAKE_C_COMPILER_ID}_${ARCHITECTURE})
    message(FATAL_ERROR "${ARCHITECTURE} is not supported")
endif()

add_library(compile_options INTERFACE)

target_compile_options(compile_options
    INTERFACE
        ${COMPILE_OPTIONS_${CMAKE_C_COMPILER_ID}}
        ${COMPILE_OPTIONS_${CMAKE_C_COMPILER_ID}_${ARCHITECTURE}}
)
