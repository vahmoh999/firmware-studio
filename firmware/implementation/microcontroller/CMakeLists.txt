add_subdirectory(${MICROCONTROLLER})

target_include_directories(microcontroller
    PRIVATE
        ${PROJECT_SOURCE_DIR}/declaration/firmware/microcontroller
        ${MICROCONTROLLER}/internal
)

target_link_libraries(microcontroller PRIVATE compile_options include_directories)
