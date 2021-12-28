#include <csapp.h>

int main(int argc, char *argv[]) {
  if (Fork() == 0) {
    Dup2(STDIN_FILENO, 3);
    Execve("fstatcheck", argv, NULL);
  }
}
