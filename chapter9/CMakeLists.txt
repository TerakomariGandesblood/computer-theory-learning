include_directories(../lib)
file(COPY ../data/story DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(ex_09_05 exercise/ex_09_05.c ../lib/csapp.c)
target_link_libraries(ex_09_05 pthread)

add_executable(hw_09_14 homework/hw_09_14.c ../lib/csapp.c)
target_link_libraries(hw_09_14 pthread)
