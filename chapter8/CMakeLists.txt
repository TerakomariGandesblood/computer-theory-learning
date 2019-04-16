include_directories(.)

add_executable(fork example/fork.c csapp.c)
target_link_libraries(fork pthread)

add_executable(waitpid example/waitpid.c csapp.c)
target_link_libraries(waitpid pthread)

add_executable(shell example/shell.c csapp.c)
target_link_libraries(shell pthread)

add_executable(kill example/kill.c csapp.c)
target_link_libraries(kill pthread)

add_executable(alarm example/alarm.c csapp.c)
target_link_libraries(alarm pthread)

add_executable(signal example/signal.c csapp.c)
target_link_libraries(signal pthread)

add_executable(snooze example/snooze.c csapp.c)
target_link_libraries(snooze pthread)

add_executable(sigprocmask example/sigprocmask.c csapp.c)
target_link_libraries(sigprocmask pthread)

add_executable(handler example/handler.c csapp.c)
target_link_libraries(handler pthread)

add_executable(handler2 example/handler2.c csapp.c)
target_link_libraries(handler2 pthread)

add_executable(jmp example/jmp.c csapp.c)
target_link_libraries(jmp pthread)

add_executable(restart example/restart.c csapp.c)
target_link_libraries(restart pthread)

add_executable(ex_8_20 homework/ex_8_20.c csapp.c)
target_link_libraries(ex_8_20 pthread)

add_executable(test test.c csapp.c)
target_link_libraries(test pthread)
