//
// Created by kaiser on 19-4-9.
//

#include <stdio.h>

#include "csapp.h"

int main(void) {
  pid_t pid;
  int x = 1;

  pid = Fork();
  if (pid == 0) {
    printf("child: x=%d\n", ++x);
  } else {
    printf("parent: x=%d\n", --x);
  }
}
