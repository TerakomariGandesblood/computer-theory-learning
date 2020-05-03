//
// Created by kaiser on 19-4-15.
//

#include "csapp.h"

int main(void) {
  sigset_t mask, prev_mask;

  Sigemptyset(&mask);
  Sigaddset(&mask, SIGINT);

  Sigprocmask(SIG_BLOCK, &mask, &prev_mask);

  Sigprocmask(SIG_SETMASK, &prev_mask, NULL);
}
