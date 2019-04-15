//
// Created by kaiser on 19-4-15.
//

#include "csapp.h"

void sigint_handler(int sig) {
  printf("Caught SIGINT!\n");
  exit(0);
}

int main(void) {
  if (signal(SIGINT, sigint_handler) == SIG_ERR) {
    unix_error("signal error");
  }

  Pause();
}
