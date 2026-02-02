if(NOT DEFINED MICROCONTROLLER)
    message(FATAL_ERROR "MICROCONTROLLER is not defined")
endif()

set(LINK_OPTIONS_GNU
    -T${CMAKE_CURRENT_SOURCE_DIR}/implementation/microcontroller/${MICROCONTROLLER}/linker.ld
    -nostdlib
)

if(NOT DEFINED LINK_OPTIONS_${CMAKE_C_COMPILER_ID})
    message(FATAL_ERROR "${CMAKE_C_COMPILER_ID} is not supported")
endif()

add_library(link_options INTERFACE)

target_link_options(link_options INTERFACE ${LINK_OPTIONS_${CMAKE_C_COMPILER_ID}})
