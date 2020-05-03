cmake_minimum_required(VERSION 3.16)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Release' as none was specified")
  set(CMAKE_BUILD_TYPE
      "Release"
      CACHE STRING "Choose the type of build" FORCE)
endif()

project(Computer-Theory-Learning LANGUAGES C CXX)

if((CMAKE_BUILD_TYPE MATCHES "Debug") OR (CMAKE_BUILD_TYPE MATCHES
    "RelWithDebInfo"))
  # Address Thread Undefined None
  set(sanitizer "Undefined")
else()
  set(sanitizer "None")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(check)
include(sanitizers)
include(compiler-options)

add_subdirectory(CSAPP)
add_subdirectory(CLRS)
