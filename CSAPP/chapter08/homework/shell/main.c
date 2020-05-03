//
// Created by kaiser on 19-4-22.
//

#include "csapp.h"
#include "job.h"
#include "shell.h"

int main(void) {
  Signal(SIGINT, HandlerSigint);
  Signal(SIGTSTP, HandlerSigtstp);
  Signal(SIGCHLD, HandlerSigchld);

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

    Eval(cmdline);
  }
}
