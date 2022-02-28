#include <arpa/inet.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  const char* str = "0x8002c2f2";
  struct in_addr addr = {htonl(strtol(str, NULL, 16))};

  char buff[32];
  char* rc = inet_ntop(AF_INET, &addr, buff, 32);
  if (!rc) {
    fprintf(stderr, "inet_ntop error: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  printf("%s\n", buff);
}
