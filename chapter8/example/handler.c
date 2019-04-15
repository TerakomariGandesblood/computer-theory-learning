//
// Created by kaiser on 19-4-15.
//

#include "csapp.h"

void handler(int sig) {
  int old_errno = errno;

  while (waitpid(-1, NULL, 0) > 0) {
    Sio_puts("Handler reaped child\n");
  }

  if (errno != ECHILD) {
    Sio_error("waitpid error");
  }

  Sleep(1);

  errno = old_errno;
}

int main(void) {
  if (signal(SIGCHLD, handler) == SIG_ERR) {
    unix_error("signal error");
  }

  for (int i = 0; i < 3; ++i) {
    if (Fork() == 0) {
      printf("Hello from child %d\n", (int)getpid());
      exit(0);
    }
  }

  char buf[MAXBUF];
  Read(STDIN_FILENO, buf, sizeof(buf));

  printf("Parent processing input\n");

  while (1) {
  }
}
