#include <csapp.h>

int main(void) {
  int fd1 = Open("foobar.txt", O_RDONLY, 0);
  int fd2 = Open("foobar.txt", O_RDONLY, 0);

  Close(fd2);
  fd2 = Open("foobar.txt", O_RDONLY, 0);

  // fd2 = 4
  printf("fd2 = %d\n", fd2);

  Close(fd1);
  Close(fd2);
}
