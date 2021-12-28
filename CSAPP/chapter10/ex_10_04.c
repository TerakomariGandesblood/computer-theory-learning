#include <csapp.h>

int main(void) {
  umask(DEF_UMASK);
  int fd = Open("a.txt", O_WRONLY | O_CREAT, DEF_MODE);
  Dup2(fd, STDIN_FILENO);

  const char *str = "Hello World!";
  Write(STDIN_FILENO, str, strlen(str));

  Close(fd);
}
