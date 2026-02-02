add_subdirectory(${ARCHITECTURE})

target_include_directories(architecture PUBLIC ${ARCHITECTURE}/declaration)

target_link_libraries(architecture PRIVATE compile_options include_directories kernel)
