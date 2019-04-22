//
// Created by kaiser on 19-4-22.
//

#include "shell.h"

#include "csapp.h"
#include "job.h"

void Eval(char *cmdline) {
  if (cmdline[0] == '\n') {
    return;
  }

  char *argv[MAXARGS];
  char buf[MAXLINE];
  strcpy(buf, cmdline);

  // true 代表在后台执行
  bool bg;
  bg = ParseLine(buf, argv);
  if (argv[0] == NULL) {
    return;
  }

  pid_t pid;
  if (!BuiltinCommand(argv)) {
    sigset_t mask_one, prev_one;
    Sigemptyset(&mask_one);
    Sigaddset(&mask_one, SIGCHLD);
    Sigprocmask(SIG_BLOCK, &mask_one, &prev_one);

    if ((pid = Fork()) == 0) {
      Sigprocmask(SIG_SETMASK, &prev_one, NULL);
      setpgid(pid, pid);

      if (execve(argv[0], argv, environ) < 0) {
        printf("%s: Command not found.\n", argv[0]);
        exit(EXIT_FAILURE);
      }
    } else {
      sigset_t mask_all, prev_all;
      Sigfillset(&mask_all);
      Sigprocmask(SIG_BLOCK, &mask_all, &prev_all);

      Jid new_jid = AddJob(pid, cmdline);

      Sigprocmask(SIG_SETMASK, &prev_one, NULL);

      if (!bg) {
        SetFgPid(pid);
        while (GetFgPid()) {
          Sigsuspend(&prev_one);
        }
      } else {
        printf("[%d] %d %s\t%s\n", new_jid, pid, "Running", cmdline);
      }
    }
  }
}

bool ParseLine(char *buf, char *argv[]) {
  // 将 \n 或者空字符替换为空格
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

bool BuiltinCommand(char *argv[]) {
  if (!strcmp(argv[0], "quit")) {
    exit(EXIT_SUCCESS);
  } else if (!strcmp(argv[0], "jobs")) {
    PrintJobs();
    return true;
  } else if (!strcmp(argv[0], "bg")) {
    BuiltinBg(argv);
    return true;
  } else if (!strcmp(argv[0], "fg")) {
    BuiltinFg(argv);
    return true;
  } else if (!strcmp(argv[0], "&")) {
    // 以 & 打头则忽略
    return true;
  }

  return false;
}

void BuiltinBg(char *argv[]) {
  if (argv[1][0] == '%') {
    int jid = strtol(argv[1] + 1, NULL, 10);
    sigset_t mask_one, prev_one;
    Sigemptyset(&mask_one);
    Sigaddset(&mask_one, SIGCHLD);
    Sigprocmask(SIG_BLOCK, &mask_one, &prev_one);

    Job *jp = FindJobByJid(jid);
    if (!jp) {
      fprintf(stderr, "No such process\n");
      return;
    }
    pid_t pid = jp->pid;
    Kill(pid, SIGCONT);

    Sigprocmask(SIG_SETMASK, &prev_one, NULL);
  } else {
    int pid = strtol(argv[1], NULL, 10);
    sigset_t mask_one, prev_one;
    Sigemptyset(&mask_one);
    Sigaddset(&mask_one, SIGCHLD);
    Sigprocmask(SIG_BLOCK, &mask_one, &prev_one);

    Job *jp = FindJobByPid(pid);
    if (!jp) {
      fprintf(stderr, "No such process\n");
      return;
    }
    pid = jp->pid;
    Kill(pid, SIGCONT);

    Sigprocmask(SIG_SETMASK, &prev_one, NULL);
  }
}

void BuiltinFg(char *argv[]) {
  if (argv[1][0] == '%') {
    int jid = strtol(argv[1] + 1, NULL, 10);
    sigset_t mask_one, prev_one;
    Sigemptyset(&mask_one);
    Sigaddset(&mask_one, SIGCHLD);
    Sigprocmask(SIG_BLOCK, &mask_one, &prev_one);

    Job *jp = FindJobByJid(jid);
    if (!jp) {
      fprintf(stderr, "No such process\n");
      return;
    }
    pid_t pid = jp->pid;
    Kill(pid, SIGCONT);
    SetFgPid(pid);

    while (GetFgPid()) {
      Sigsuspend(&prev_one);
    }

    Sigprocmask(SIG_SETMASK, &prev_one, NULL);
  } else {
    int pid = strtol(argv[1], NULL, 10);
    sigset_t mask_one, prev_one;
    Sigemptyset(&mask_one);
    Sigaddset(&mask_one, SIGCHLD);
    Sigprocmask(SIG_BLOCK, &mask_one, &prev_one);

    Job *jp = FindJobByPid(pid);
    if (!jp) {
      fprintf(stderr, "No such process\n");
      return;
    }
    pid = jp->pid;
    Kill(pid, SIGCONT);
    SetFgPid(pid);

    while (GetFgPid()) {
      Sigsuspend(&prev_one);
    }

    Sigprocmask(SIG_SETMASK, &prev_one, NULL);
  }
}
