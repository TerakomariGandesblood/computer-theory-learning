//
// Created by kaiser on 19-4-22.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  sleep(strtol(argv[1], NULL, 10));
  printf("ok\n");
}
