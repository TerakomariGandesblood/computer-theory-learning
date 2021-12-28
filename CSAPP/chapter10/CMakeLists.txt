file(GLOB CTL_DATA_FILE CONFIGURE_DEPENDS "../data/*")
file(COPY ${CTL_DATA_FILE} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(ex_10_01 ex_10_01.c)
target_link_libraries(ex_10_01 csapp::csapp)

add_executable(ex_10_02 ex_10_02.c)
target_link_libraries(ex_10_02 csapp::csapp)

add_executable(ex_10_03 ex_10_03.c)
target_link_libraries(ex_10_03 csapp::csapp)

add_executable(ex_10_04 ex_10_04.c)
target_link_libraries(ex_10_04 csapp::csapp)

add_executable(ex_10_05 ex_10_05.c)
target_link_libraries(ex_10_05 csapp::csapp)

add_executable(ex_10_06 ex_10_06.c)
target_link_libraries(ex_10_06 csapp::csapp)

add_executable(ex_10_07 ex_10_07.c)
target_link_libraries(ex_10_07 csapp::csapp)

add_executable(ex_10_08 ex_10_08.c)
target_link_libraries(ex_10_08 csapp::csapp)

add_executable(ex_10_09 ex_10_09.c)
target_link_libraries(ex_10_09 csapp::csapp)

add_executable(ex_10_10 ex_10_10.c)
target_link_libraries(ex_10_10 csapp::csapp)
