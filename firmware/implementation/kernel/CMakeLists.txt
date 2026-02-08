add_library(kernel OBJECT initialization.c scheduler.c)

target_include_directories(kernel
    PRIVATE
        ${PROJECT_SOURCE_DIR}/declaration/firmware/kernel
        internal
)

target_link_libraries(kernel PRIVATE compile_options include_directories service)
