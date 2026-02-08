add_subdirectory(architecture)
add_subdirectory(kernel)
add_subdirectory(microcontroller)
add_subdirectory(service)

add_executable(firmware
    $<TARGET_OBJECTS:architecture>
    $<TARGET_OBJECTS:kernel>
    $<TARGET_OBJECTS:microcontroller>
    $<TARGET_OBJECTS:service>
)

target_link_libraries(firmware PRIVATE link_options)

set_target_properties(firmware PROPERTIES SUFFIX ".elf")

if(MICROCONTROLLER STREQUAL "rp2350")
    find_program(PICOTOOL NAMES picotool picotool.exe PATHS ${CMAKE_CURRENT_SOURCE_DIR} REQUIRED)
    add_custom_command(TARGET firmware POST_BUILD COMMAND ${PICOTOOL} uf2 convert firmware.elf firmware.uf2)
endif()
