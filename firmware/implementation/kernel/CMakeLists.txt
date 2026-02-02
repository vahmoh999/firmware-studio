add_library(kernel OBJECT initialization.c)

target_include_directories(kernel PUBLIC declaration)

target_link_libraries(kernel PRIVATE compile_options include_directories microcontroller)
