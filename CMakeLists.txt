cmake_minimum_required(VERSION 3.19)
project(SandBox_C C)

set(CMAKE_C_STANDARD 11)

add_executable(SandBox_C main.c List.c List.h)
add_compile_options(-Wall -Wextra -pedantic -Werror)