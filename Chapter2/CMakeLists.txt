cmake_minimum_required(VERSION 3.12)
project(Chapter2)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

file(GLOB csrc "*.h" "*.c")
add_executable(Chapter2 ${csrc})