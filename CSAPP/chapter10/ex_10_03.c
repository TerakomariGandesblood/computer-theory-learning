#include <csapp.h>

int main(void) {
  int fd = Open("foobar.txt", O_RDONLY, 0);

  char c;
  if (Fork() == 0) {
    Read(fd, &c, 1);
    exit(EXIT_SUCCESS);
  }
  Wait(NULL);

  Read(fd, &c, 1);

  // c = o
  printf("c = %c\n", c);
}
