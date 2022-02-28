include_directories(../lib)

add_executable(ex_11_02 ex_11_02.c)
add_executable(ex_11_03 ex_11_03.c)
add_executable(ex_11_04 ex_11_04.c)
target_link_libraries(ex_11_04 PRIVATE csapp::csapp)

add_executable(echo_client echo_client.c)
target_link_libraries(echo_client PRIVATE csapp::csapp)

add_executable(echo_server echo_server.c)
target_link_libraries(echo_server PRIVATE csapp::csapp)
