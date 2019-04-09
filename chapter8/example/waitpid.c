//
// Created by kaiser on 19-4-9.
//

#include <stdio.h>

#include "csapp.h"

#define N 2

int main(void) {
  int status;
  pid_t pid[N], retpid;
  int i = 0;

  for (; i < N; i++) {
    if ((pid[i] = Fork()) == 0) {
      exit(100 + i);
    }
  }

  i = 0;

  while ((retpid = waitpid(pid[i++], &status, 0)) > 0) {
    if (WIFEXITED(status)) {
      printf("child %d terminated normally with exit status=%d\n", retpid,
             WEXITSTATUS(status));
    } else {
      printf("child %d terminated abnormally\n", retpid);
    }
  }

  if (errno != ECHILD) {
    unix_error("waitpid error");
  }
}
