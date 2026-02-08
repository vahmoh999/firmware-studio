add_subdirectory(${ARCHITECTURE})

target_include_directories(architecture
    PRIVATE
        ${PROJECT_SOURCE_DIR}/declaration/firmware/architecture
        ${ARCHITECTURE}/internal
)

target_link_libraries(architecture PRIVATE compile_options include_directories kernel)
