//
// Created by kaiser on 19-4-15.
//

#include "csapp.h"

unsigned snooze(unsigned secs) {
  unsigned ret = sleep(secs);
  printf("Slept for %u of %u secs\n", secs - ret, secs);
  return ret;
}

void sigint_handler(int sig) {}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "args error\n");
    return EXIT_FAILURE;
  }

  if (signal(SIGINT, sigint_handler) == SIG_ERR) {
    unix_error("signal error");
  }

  snooze(strtoul(argv[1], NULL, 10));
}
