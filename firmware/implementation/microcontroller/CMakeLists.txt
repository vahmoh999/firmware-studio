add_subdirectory(${MICROCONTROLLER})

target_include_directories(microcontroller PUBLIC ${MICROCONTROLLER}/declaration)

target_link_libraries(microcontroller PRIVATE compile_options include_directories)
