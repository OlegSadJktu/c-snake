# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.23)
project(snake C)

set(CMAKE_C_STANDARD 11)

include_directories(new_sn)

add_executable(snake
        new_sn/apple.c
        new_sn/apple.h
        new_sn/direction.c
        new_sn/direction.h
        new_sn/double_list.c
        new_sn/double_list.h
        new_sn/main.c
        new_sn/snake.c
        new_sn/snake.h
        new_sn/world.c
        new_sn/world.c
        )
        # test/test.c)


if(MSVC)
  target_compile_options(snake PRIVATE /W4 /WX)
else()
  target_compile_options(snake PRIVATE -Wall )
endif()

target_link_libraries(snake ncursesw)
