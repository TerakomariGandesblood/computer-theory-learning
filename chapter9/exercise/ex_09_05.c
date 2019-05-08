//
// Created by kaiser on 19-5-8.
//

#include "csapp.h"

void mmapcopy(int fd, int size) {
  char *buf = Mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
  Write(STDOUT_FILENO, buf, size);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "need a file name\n");
    return EXIT_FAILURE;
  }

  struct stat stat;

  // 第三个参数指定新文件的访问权限位, 0 代表什么权限都没有
  int fd = Open(argv[1], O_RDONLY, 0);
  // 获取文件信息
  fstat(fd, &stat);
  mmapcopy(fd, stat.st_size);
  close(fd);
}
