//
// Created by kaiser on 19-4-10.
//

#include "csapp.h"

int main(void) {
  printf("%d\n", getpid());
  // Kill(getpid(), SIGSTOP);
  Pause();
  printf("test\n");
}
