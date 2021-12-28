include_directories(../lib)

add_executable(fork example/fork.c ../lib/csapp.c)
target_link_libraries(fork pthread)

add_executable(waitpid example/waitpid.c ../lib/csapp.c)
target_link_libraries(waitpid pthread)

add_executable(kill example/kill.c ../lib/csapp.c)
target_link_libraries(kill pthread)

add_executable(alarm example/alarm.c ../lib/csapp.c)
target_link_libraries(alarm pthread)

add_executable(signal example/signal.c ../lib/csapp.c)
target_link_libraries(signal pthread)

add_executable(snooze example/snooze.c ../lib/csapp.c)
target_link_libraries(snooze pthread)

add_executable(sigprocmask example/sigprocmask.c ../lib/csapp.c)
target_link_libraries(sigprocmask pthread)

add_executable(handler example/handler.c ../lib/csapp.c)
target_link_libraries(handler pthread)

add_executable(handler2 example/handler2.c ../lib/csapp.c)
target_link_libraries(handler2 pthread)

add_executable(jmp example/jmp.c ../lib/csapp.c)
target_link_libraries(jmp pthread)

add_executable(restart example/restart.c ../lib/csapp.c)
target_link_libraries(restart pthread)

add_executable(wait_for_signal example/wait_for_signal.c ../lib/csapp.c)
target_link_libraries(wait_for_signal pthread)

add_executable(myls homework/myls.c ../lib/csapp.c)
target_link_libraries(myls pthread)

add_executable(mysystem homework/mysystem.c ../lib/csapp.c)
target_link_libraries(mysystem pthread)

add_executable(hw_8_23 homework/hw_8_23.c ../lib/csapp.c)
target_link_libraries(hw_8_23 pthread)

add_executable(hw_8_24 homework/hw_8_24.c ../lib/csapp.c)
target_link_libraries(hw_8_24 pthread)

add_executable(hw_8_25 homework/hw_8_25.c ../lib/csapp.c)
target_link_libraries(hw_8_25 pthread)

add_executable(
  shell homework/shell/main.c homework/shell/job.c homework/shell/job.h
        homework/shell/shell.c homework/shell/shell.h ../lib/csapp.c)
target_link_libraries(shell pthread)

add_executable(foo homework/shell/foo.c)
target_link_libraries(foo pthread)
