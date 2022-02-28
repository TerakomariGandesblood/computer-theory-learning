#include <arpa/inet.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  const char* str = "128.2.194.242";

  struct in_addr addr;
  int rc = inet_pton(AF_INET, str, &addr);
  if (rc != 1) {
    fprintf(stderr, "inet_pton error: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  printf("%#x\n", ntohl(addr.s_addr));
}
