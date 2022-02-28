#include "csapp.h"

int open_listen_fd(const char *port) {
  struct addrinfo hints;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_ADDRCONFIG | AI_NUMERICSERV | AI_PASSIVE;

  struct addrinfo *result;
  Getaddrinfo(NULL, port, &hints, &result);

  int listen_fd;
  struct addrinfo *iter = result;
  int opt = 1;
  for (; iter; iter = iter->ai_next) {
    if ((listen_fd = socket(iter->ai_family, iter->ai_socktype,
                            iter->ai_protocol)) < 0) {
      continue;
    }

    Setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));

    if (bind(listen_fd, iter->ai_addr, iter->ai_addrlen) == 0) {
      break;
    }

    Close(listen_fd);
  }

  Freeaddrinfo(result);

  if (!iter) {
    return -1;
  }

  if (listen(listen_fd, LISTENQ) < 0) {
    Close(listen_fd);
    return -1;
  }

  return listen_fd;
}

void echo(int conn_fd) {
  rio_t rio;
  rio_readinitb(&rio, conn_fd);

  char buf[MAXLINE];
  size_t n;
  while ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
    printf("server received %d bytes\n", (int)n);
    Rio_writen(conn_fd, buf, n);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int listen_fd = open_listen_fd(argv[1]);
  struct sockaddr_storage client_addr;
  int client_len = sizeof(struct sockaddr_storage);
  char client_hostname[MAXLINE];
  char client_port[MAXLINE];
  while (1) {
    int conn_fd = Accept(listen_fd, (SA *)&client_addr, &client_len);
    Getnameinfo((SA *)&client_addr, client_len, client_hostname, MAXLINE,
                client_port, MAXLINE, 0);
    printf("Connected to (%s, %s)\n", client_hostname, client_port);
    echo(conn_fd);
    Close(conn_fd);
  }
}
