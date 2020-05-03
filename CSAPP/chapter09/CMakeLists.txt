include_directories(../lib)

add_executable(ex_09_05 exercise/ex_09_05.c ../lib/csapp.c)
target_link_libraries(ex_09_05 pthread)
