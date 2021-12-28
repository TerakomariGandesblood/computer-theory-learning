#include <csapp.h>

int main(void) {
  int fd1 = Open("foobar.txt", O_RDONLY, 0);
  int fd2 = Open("foobar.txt", O_RDONLY, 0);

  char c;

  Read(fd1, &c, 1);
  // c = f
  printf("c = %c\n", c);

  Read(fd2, &c, 1);
  // c = f
  printf("c = %c\n", c);

  Close(fd1);
  Close(fd2);
}
