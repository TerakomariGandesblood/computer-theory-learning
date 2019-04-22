//
// Created by kaiser on 19-4-22.
//

#include <stdbool.h>

#include "csapp.h"

#define MAXARGS 128

int jid_counter = 1;

struct Job {
  int pid;
  int jid;
  bool bg;
  bool is_run;
  const char *arg;
};

volatile int jobs_index = 0;

volatile struct Job jobs[100];

volatile pid_t fg_pid = 0;

void eval(char *cmdline);
bool parseline(char *buf, char *argv[]);
bool builtin_command(char *argv[]);

void builtin_jobs(void);
void builtin_bg(char *argv[]);
void builtin_fg(char *argv[]);

void handler_sigint(int sig);
void handler_sigtstp(int sig);
void handler_sigchld(int sig);

int main(void) {
  Signal(SIGINT, handler_sigint);
  Signal(SIGTSTP, handler_sigtstp);
  Signal(SIGCHLD, handler_sigchld);

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
      sigset_t mask, prev;
      Sigfillset(&mask);
      Sigprocmask(SIG_BLOCK, &mask, &prev);

      struct Job job = {pid, jid_counter++, bg, true, cmdline};
      jobs[jobs_index++] = job;

      if (!bg) {
        int status;
        fg_pid = pid;
        if (waitpid(pid, &status, 0) < 0) {
          unix_error("waitfg: waitpid error");
        }
      } else {
        printf("[%d] %d %s\t%s\n", jid_counter - 1, pid, "Running", cmdline);
      }
      Sigprocmask(SIG_SETMASK, &prev, NULL);
    }
  }
}

bool parseline(char *buf, char *argv[]) {
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

bool builtin_command(char *argv[]) {
  if (!strcmp(argv[0], "quit")) {
    exit(EXIT_SUCCESS);
  } else if (!strcmp(argv[0], "jobs")) {
    builtin_jobs();
    return true;
  } else if (!strcmp(argv[0], "bg")) {
    builtin_bg(argv);
    return true;
  } else if (!strcmp(argv[0], "fg")) {
    builtin_fg(argv);
    return true;
  } else if (!strcmp(argv[0], "&")) {
    // 以 & 打头则忽略
    return true;
  }

  return false;
}

void builtin_jobs(void) {
  sigset_t mask, prev;
  Sigfillset(&mask);
  Sigprocmask(SIG_BLOCK, &mask, &prev);

  for (int i = 0; i < jobs_index; ++i) {
    if (jobs[i].bg) {
      printf("[%d] %d %s\t%s\n", jobs[i].jid, jobs[i].pid,
             (jobs[i].is_run ? "Running" : "Stopped"), jobs[i].arg);
    }
  }
  Sigprocmask(SIG_SETMASK, &prev, NULL);
}

void builtin_fg(char *argv[]) {
  if (argv[1][0] == '%') {
    int jid = strtol(argv[0] + 1, NULL, 10);
    sigset_t mask, prev;
    Sigfillset(&mask);
    Sigprocmask(SIG_BLOCK, &mask, &prev);

    for (int i = 0; i < jobs_index; ++i) {
      if (jobs[i].jid == jid) {
        Kill(jobs[i].pid, SIGCONT);
        Waitpid(jobs[i].pid, NULL, 0);
        Sigprocmask(SIG_SETMASK, &prev, NULL);
        return;
      }
    }
    unix_error("No such process");
  } else {
    int pid = strtol(argv[0], NULL, 10);
    sigset_t mask, prev;
    Sigfillset(&mask);
    Sigprocmask(SIG_BLOCK, &mask, &prev);

    for (int i = 0; i < jobs_index; ++i) {
      if (jobs[i].pid == pid) {
        Kill(pid, SIGCONT);
        Waitpid(pid, NULL, 0);
        Sigprocmask(SIG_SETMASK, &prev, NULL);
        return;
      }
    }
    unix_error("No such process");
  }
}

void builtin_bg(char *argv[]) {
  if (argv[1][0] == '%') {
    int jid = strtol(argv[0] + 1, NULL, 10);
    sigset_t mask, prev;
    Sigfillset(&mask);
    Sigprocmask(SIG_BLOCK, &mask, &prev);

    for (int i = 0; i < jobs_index; ++i) {
      if (jobs[i].jid == jid) {
        Kill(jobs[i].pid, SIGCONT);
        Sigprocmask(SIG_SETMASK, &prev, NULL);
        return;
      }
    }
    unix_error("No such process");
  } else {
    int pid = strtol(argv[0], NULL, 10);
    sigset_t mask, prev;
    Sigfillset(&mask);
    Sigprocmask(SIG_BLOCK, &mask, &prev);

    for (int i = 0; i < jobs_index; ++i) {
      if (jobs[i].pid == pid) {
        Kill(pid, SIGCONT);
        Sigprocmask(SIG_SETMASK, &prev, NULL);
        return;
      }
    }
    unix_error("No such process");
  }
}

void handler_sigint(int sig) {
  Sio_error("fuck you");
  int olderrno = errno;
  sigset_t mask, prev;
  Sigfillset(&mask);
  Sigprocmask(SIG_BLOCK, &mask, &prev);

  if (fg_pid == 0) {
    Kill(getpid(), SIGINT);
  } else {
    for (int i = 0; i < jobs_index; ++i) {
      if (jobs[i].pid == fg_pid) {
        jobs[i].is_run = false;
      }
    }

    Kill(fg_pid, SIGINT);
    fg_pid = 0;
  }

  Sigprocmask(SIG_SETMASK, &prev, NULL);
  errno = olderrno;
}

void handler_sigtstp(int sig) {
  Sio_error("fuck you1");
  int olderrno = errno;
  sigset_t mask, prev;
  Sigfillset(&mask);
  Sigprocmask(SIG_BLOCK, &mask, &prev);

  if (fg_pid == 0) {
    Kill(getpid(), SIGTSTP);
  } else {
    for (int i = 0; i < jobs_index; ++i) {
      if (jobs[i].pid == fg_pid) {
        jobs[i].is_run = false;
      }
    }

    Kill(fg_pid, SIGTSTP);
  }

  Sigprocmask(SIG_SETMASK, &prev, NULL);
  errno = olderrno;
}

void handler_sigchld(int sig) {
  Sio_error("fuck you2");
  int olderrno = errno;
  sigset_t mask, prev;
  Sigfillset(&mask);
  Sigprocmask(SIG_BLOCK, &mask, &prev);

  int status;
  pid_t pid;

  while ((pid = waitpid(-1, &status, 0)) > 0) {
    if (WIFSIGNALED(status)) {
      printf("Job %d terminated by signal: %s", pid,
             strsignal(WTERMSIG(status)));
    }
    int i = 0;
    for (; i < jobs_index; ++i) {
      if (jobs[i].pid == pid) {
        break;
      }
    }
    --jobs_index;
    struct Job temp = jobs[i];
    jobs[i] = jobs[jobs_index];
    jobs[jobs_index] = temp;
  }

  if (errno != ECHILD) {
    unix_error("waitpid error");
  }

  Sigprocmask(SIG_SETMASK, &prev, NULL);
  errno = olderrno;
}
