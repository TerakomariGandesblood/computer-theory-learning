//
// Created by kaiser on 19-4-10.
//

#include <stdbool.h>

#include "csapp.h"

#define MAXARGS 128

void eval(char *cmdline);
bool parseline(char *buf, char *argv[]);
bool builtin_command(char *argv[]);

int main(void) {
  char cmdline[MAXARGS];

  while (true) {
    printf("> ");
    // 从给定文件流读取最多 count - 1 个字符并将它们存储于 str
    // 所指向的字符数组.若文件尾出现或发现换行符则终止分析, 后一情况下 str
    // 将包含一个换行符.若无错误发生, 则紧随写入到 str
    // 的最后一个字符后写入空字符.若 count 小于 1 则行为未定义
    Fgets(cmdline, MAXLINE, stdin);
    if (feof(stdin)) {
      exit(0);
    }

    eval(cmdline);
  }
}

void eval(char *cmdline) {
  char *argv[MAXARGS];
  char buf[MAXLINE];
  strcpy(buf, cmdline);

  // true 代表在后台执行
  bool bg;
  bg = parseline(buf, argv);
  if (argv[0] == NULL) {
    return;
  }

  pid_t pid;
  if (!builtin_command(argv)) {
    if ((pid = Fork()) == 0) {
      if (execve(argv[0], argv, environ) < 0) {
        printf("%s: Command not found.\n", argv[0]);
        exit(EXIT_FAILURE);
      }
    } else {
      if (!bg) {
        int status;
        if (waitpid(pid, &status, 0) < 0) {
          unix_error("waitfg: waitpid error");
        }
      } else {
        printf("%d %s", pid, cmdline);
      }
    }
  }
}

bool parseline(char *buf, char *argv[]) {
  // 将 \n 替换为空格
  buf[strlen(buf) - 1] = ' ';
  // 忽略前面的空格
  while (*buf && (*buf == ' ')) {
    buf++;
  }

  int argc = 0;
  char *delim;
  // 寻找空格首次出现的位置
  while ((delim = strchr(buf, ' '))) {
    argv[argc++] = buf;
    *delim = '\0';
    buf = delim + 1;
    while (*buf && (*buf == ' ')) {
      buf++;
    }
  }

  argv[argc] = NULL;

  bool bg;
  if ((bg = (*argv[argc - 1] == '&')) != 0) {
    argv[--argc] = NULL;
  }

  return bg;
}

bool builtin_command(char *argv[]) {
  if (!strcmp(argv[0], "quit")) {
    exit(EXIT_SUCCESS);
  }

  // 忽略开头的 &
  if (!strcmp(argv[0], "&")) {
    return true;
  }

  return false;
}
