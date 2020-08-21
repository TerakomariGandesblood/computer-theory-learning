set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")

enable_testing()
find_package(GTest REQUIRED)

add_subdirectory(chapter02)
