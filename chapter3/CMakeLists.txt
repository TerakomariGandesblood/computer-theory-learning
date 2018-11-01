cmake_minimum_required(VERSION 3.12)
project(chapter3)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c17 -Wall -Wextra")

file(GLOB csrc "*.h" "*.c" "test/*.c")
add_executable(chapter3 ${csrc})