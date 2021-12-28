#include <csapp.h>

int main(void) {
  int fd1 = Open("foobar.txt", O_RDONLY, 0);
  int fd2 = Open("foobar.txt", O_RDONLY, 0);

  char c;
  Read(fd2, &c, 1);
  Dup2(fd2, fd1);
  Read(fd1, &c, 1);

  // c = o
  printf("c = %c\n", c);
}
