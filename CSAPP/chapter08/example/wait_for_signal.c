//
// Created by kaiser on 19-4-16.
//

#include <stdbool.h>

#include "csapp.h"

volatile sig_atomic_t pid;

void sigchld_handler(int sig) {
  int old_errno = errno;
  pid = Waitpid(-1, NULL, 0);
  errno = old_errno;
}

int main(void) {
  sigset_t mask, prev;

  Signal(SIGCHLD, sigchld_handler);
  Signal(SIGINT, SIG_IGN);
  Sigemptyset(&mask);
  Sigaddset(&mask, SIGCHLD);

  while (true) {
    Sigprocmask(SIG_BLOCK, &mask, &prev);
    if (Fork() == 0) {
      exit(EXIT_SUCCESS);
    }

    // 如果不阻塞 SIGCHLD, 可能在执行下面的语句之前, 该信号
    // 就处理完毕了, 从而下面的循环不会退出
    pid = 0;

    while (!pid) {
      Sigsuspend(&prev);
    }

    Sigprocmask(SIG_SETMASK, &prev, NULL);

    printf(".");
    exit(EXIT_SUCCESS);
  }
}
