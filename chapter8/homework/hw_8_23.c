//
// Created by kaiser on 19-4-21.
//

#include "csapp.h"

volatile int counter = 0;

void handler(int sig) {
  int olderrnr = errno;
  sigset_t mask, prev;
  sigfillset(&mask);
  Sigprocmask(SIG_BLOCK, &mask, &prev);

  while (waitpid(-1, NULL, 0) > 0) {
    ++counter;
  }

  if (errno != ECHILD) {
    Sio_error("waitpid error");
  }

  Sigprocmask(SIG_SETMASK, &prev, NULL);
  errno = olderrnr;
}

int main(void) {
  Signal(SIGUSR2, handler);

  for (int i = 0; i < 5; i++) {
    if (Fork() == 0) {
      Kill(getppid(), SIGUSR2);
      printf("sent SIGUSER2 to parent\n");
      exit(0);
    }
  }

  waitpid(-1, NULL, 0);

  printf("counter = %d\n", counter);
}
