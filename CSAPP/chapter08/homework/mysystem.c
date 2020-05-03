//
// Created by kaiser on 19-4-21.
//

#include "csapp.h"

int mysystem(const char *command) {
  pid_t pid;
  int status;

  if ((pid = Fork()) == 0) {
    // 注意参数从第二个开始
    const char *commands[4] = {"", "-c", command, NULL};
    Execve("/bin/sh", commands, environ);
  } else {
    Waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
      return WEXITSTATUS(status);
    } else if (WIFSIGNALED(status)) {
      return WTERMSIG(status);
    } else {
      return -1;
    }
  }
}

int main(void) { mysystem("gcc -v"); }
