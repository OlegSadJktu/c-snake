# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.23)
project(shake C)

set(CMAKE_C_STANDARD 11)

include_directories(new_sn)

add_executable(shake
        new_sn/direction.c
        new_sn/direction.h
        new_sn/double_list.c
        new_sn/double_list.h
        new_sn/new_snake.c
        new_sn/snake.c
        new_sn/snake.h
        test/test.c)

target_link_libraries(shake ncursesw)
