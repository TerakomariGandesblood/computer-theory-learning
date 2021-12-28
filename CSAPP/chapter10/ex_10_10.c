#include <csapp.h>

int main(int argc, char *argv[]) {
  rio_t rio;
  char buf[MAXBUF];

  int fd;
  if (argc > 1) {
    fd = Open(argv[1], O_RDONLY, 0);
    Dup2(fd, STDIN_FILENO);
  }

  Rio_readinitb(&rio, STDIN_FILENO);

  ssize_t n;
  while ((n = Rio_readlineb(&rio, buf, MAXBUF)) != 0) {
    Rio_writen(STDOUT_FILENO, buf, n);
  }

  if (argc > 1) {
    Close(fd);
  }
}
