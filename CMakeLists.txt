cmake_minimum_required(VERSION 3.19)
project(192 C)

set(CMAKE_C_STANDARD 99)

add_executable(192 main.c)

add_library(data_structures
        libs/data_structures/vector/vector.c
)

target_include_directories(data_structures PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/data_structures/vector/)

target_link_libraries(192 PRIVATE data_structures)
