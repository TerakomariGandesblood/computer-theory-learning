#include "csapp.h"

int open_client_fd(const char *hostname, const char *port) {
  struct addrinfo hints;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_ADDRCONFIG | AI_NUMERICHOST;

  struct addrinfo *result;
  Getaddrinfo(hostname, port, &hints, &result);

  int client_fd;
  struct addrinfo *iter = result;
  for (; iter; iter = iter->ai_next) {
    if ((client_fd = socket(iter->ai_family, iter->ai_socktype,
                            iter->ai_protocol)) < 0) {
      continue;
    }

    if (connect(client_fd, iter->ai_addr, iter->ai_addrlen) != -1) {
      break;
    }

    Close(client_fd);
  }

  Freeaddrinfo(result);

  if (!iter) {
    return -1;
  } else {
    return client_fd;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  const char *hostname = argv[1];
  const char *port = argv[2];
  int client_fd = open_client_fd(hostname, port);

  rio_t rio;
  Rio_readinitb(&rio, client_fd);

  char buf[MAXLINE];
  while (Fgets(buf, MAXLINE, stdin) != NULL) {
    Rio_writen(client_fd, buf, strlen(buf));
    Rio_readlineb(&rio, buf, MAXLINE);
    Fputs(buf, stdout);
  }

  Close(client_fd);
}
