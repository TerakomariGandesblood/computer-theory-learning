//
// Created by kaiser on 19-4-22.
//

#include "csapp.h"

void fuck(int sig) { Sio_puts("fuck you"); }

int main(void) {
  Signal(SIGTSTP, fuck);

  if (Fork() == 0) {
    Kill(getpid(), SIGTSTP);
  }
}
