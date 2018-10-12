cmake_minimum_required(VERSION 3.12)
project(chapter2)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

file(GLOB csrc "*.h" "*.c" "homework/*.c")
add_executable(chapter2 ${csrc})