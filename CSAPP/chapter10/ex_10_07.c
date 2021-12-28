#include <csapp.h>

int main(void) {
  rio_t rio;
  char buf[MAXBUF];

  Rio_readinitb(&rio, STDIN_FILENO);

  ssize_t n;
  while ((n = Rio_readnb(&rio, buf, MAXBUF)) != 0) {
    Rio_writen(STDOUT_FILENO, buf, n);
  }
}
