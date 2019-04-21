//
// Created by kaiser on 19-4-9.
//

#include "csapp.h"

int main(int argc, char *argv[], char *envp[]) {
  Execve("/bin/ls", argv, envp);
}
