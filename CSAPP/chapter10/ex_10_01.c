#include <csapp.h>

int main(void) {
  int fd1 = Open("story.txt", O_RDONLY, 0);
  Close(fd1);

  int fd2 = Open("story.txt", O_RDONLY, 0);
  // fd2 = 3
  printf("fd2 = %d\n", fd2);
  Close(fd2);
}
