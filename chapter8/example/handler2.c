//
// Created by kaiser on 19-4-15.
//

#include "csapp.h"

volatile long counter = 2;

void handler(int sig) {
  sigset_t mask, prev_mask;

  Sigfillset(&mask);
  Sigprocmask(SIG_BLOCK, &mask, &prev_mask);
  Sio_putl(--counter);
  Sio_puts("\n");
  Sigprocmask(SIG_SETMASK, &prev_mask, NULL);

  _exit(0);
}

int main(void) {
  printf("%ld\n", counter);
  fflush(stdout);

  // 用户定义的信号1, 默认行为是终止
  signal(SIGUSR1, handler);

  pid_t pid;
  if ((pid = Fork()) == 0) {
    while (1) {
    }
  }

  Kill(pid, SIGUSR1);
  Waitpid(-1, NULL, 0);

  sigset_t mask, prev_mask;
  Sigfillset(&mask);
  Sigprocmask(SIG_BLOCK, &mask, &prev_mask);
  printf("%ld\n", ++counter);
  Sigprocmask(SIG_SETMASK, &prev_mask, NULL);
}
