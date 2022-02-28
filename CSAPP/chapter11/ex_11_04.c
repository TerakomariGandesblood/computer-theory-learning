#include "csapp.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s <domain name>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  struct addrinfo hints;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_ADDRCONFIG;

  struct addrinfo *result;
  Getaddrinfo(argv[1], NULL, &hints, &result);

  char buf[MAXBUF];
  for (struct addrinfo *p = result; p; p = p->ai_next) {
    struct sockaddr_in *sockaddr = p->ai_addr;
    printf("%s\n", inet_ntop(AF_INET, &(sockaddr->sin_addr), buf, MAXBUF));
  }

  Freeaddrinfo(result);
}
