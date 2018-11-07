cmake_minimum_required(VERSION 3.12)
project(chapter3)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

file(GLOB csrc "*.h" "*.c" "test/*.c")
add_executable(${PROJECT_NAME} ${csrc})