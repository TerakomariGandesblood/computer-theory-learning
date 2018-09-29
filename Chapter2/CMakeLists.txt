cmake_minimum_required(VERSION 3.12)
project(Chapter2 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_executable(Chapter2 test.c)