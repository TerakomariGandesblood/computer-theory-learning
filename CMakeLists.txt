cmake_minimum_required(VERSION 3.13)
project(CSAPP LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

#add_subdirectory(chapter2)
#add_subdirectory(chapter3)
#add_subdirectory(chapter5)