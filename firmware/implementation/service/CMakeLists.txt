add_library(service OBJECT sio.c uart.c)

target_include_directories(service
    PRIVATE
        ${PROJECT_SOURCE_DIR}/declaration/firmware/service
        internal
)

target_link_libraries(service PRIVATE compile_options include_directories microcontroller)
