//
// Created by kaiser on 19-4-21.
//

#include "csapp.h"

#define N 2

int main(void) {
  for (int i = 0; i < N; i++) {
    if (Fork() == 0) {
      Kill(getpid(), SIGSEGV);
    }
  }

  int status;
  pid_t pid;
  while ((pid = waitpid(-1, &status, 0)) > 0) {
    if (WIFEXITED(status)) {
      printf("child %d terminated normally with exit status=%d\n", pid,
             WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
      printf("child %d terminated by signal %d:%s\n", pid, WTERMSIG(status),
             strsignal(WTERMSIG(status)));
    } else {
      printf("child %d terminated abnormally\n", pid);
    }
  }

  if (errno != ECHILD) {
    unix_error("waitpid error");
  }
}
