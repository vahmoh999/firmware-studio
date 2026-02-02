cmake_minimum_required(VERSION 4.1)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

project(firmware)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(configuration/CompileOptions.cmake)
include(configuration/IncludeDirectories.cmake)
include(configuration/LinkOptions.cmake)

add_subdirectory(implementation)
