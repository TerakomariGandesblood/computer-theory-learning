//
// Created by kaiser on 19-4-22.
//

#include "job.h"

static volatile sig_atomic_t fg_pid;
static volatile Job jobs[MAXJOBS];
static volatile size_t jobs_index;
static volatile int jid_counter;

static bool NoOtherProcess() { return fg_pid == 0; }

bool IsFgPid(pid_t pid) { return fg_pid == pid; }

pid_t GetFgPid() { return fg_pid; }

void SetFgPid(pid_t pid) { fg_pid = pid; }

void PrintJobs() {
  for (int i = 0; i < jobs_index; ++i) {
    printf("[%d] %d %s\t%s\n", jobs[i].jid, jobs[i].pid,
           (jobs[i].is_run ? "Running" : "Stopped"), jobs[i].cmdline);
  }
}

int AddJob(pid_t pid, const char *cmdline) {
  if (jobs_index < MAXJOBS) {
    Job job = {jid_counter, pid, true};
    strcpy(job.cmdline, cmdline);
    jobs[jobs_index++] = job;
    return jid_counter++;
  } else {
    unix_error("too many jobs");
  }
}

void DeleteJob(pid_t pid) {
  int i = 0;
  for (; i < jobs_index; ++i) {
    if (jobs[i].pid == pid) {
      break;
    }
  }

  jobs[i] = jobs[--jobs_index];
}

Job *FindJobByPid(pid_t pid) {
  for (int i = 0; i < jobs_index; ++i) {
    if (jobs[i].pid == pid) {
      return (Job *)&jobs[i];
    }
  }
  return NULL;
}

Job *FindJobByJid(Jid jid) {
  for (int i = 0; i < jobs_index; ++i) {
    if (jobs[i].jid == jid) {
      return (Job *)&jobs[i];
    }
  }
  return NULL;
}

void SetStatus(Job *jp, bool is_run) { jp->is_run = is_run; }

void HandlerSigchld(int sig) {
  int old_errno = errno;

  sigset_t mask_all, prev_all;
  Sigfillset(&mask_all);

  pid_t pid;
  int status;

  // 有停止/终止/停止并收到 SIGCONT 的子进程则返回 pid , 否则立即返回 0
  while ((pid = waitpid(-1, &status, WNOHANG | WUNTRACED | WCONTINUED)) > 0) {
    if (WIFEXITED(status) || WIFSIGNALED(status)) {
      if (IsFgPid(pid)) {
        SetFgPid(0);
      }

      if (WIFSIGNALED(status)) {
        Sio_puts("Job ");
        Sio_putl(pid);
        Sio_puts(" terminated by signal: ");
        Sio_puts(strsignal(WTERMSIG(status)));
        Sio_puts("\n");
      }

      Sigprocmask(SIG_BLOCK, &mask_all, &prev_all);
      DeleteJob(pid);
      Sigprocmask(SIG_SETMASK, &prev_all, NULL);
    } else if (WIFSTOPPED(status)) {
      if (IsFgPid(pid)) {
        SetFgPid(0);
      }

      Sio_puts("Job ");
      Sio_putl(pid);
      Sio_puts(" stopped by signal: ");
      Sio_puts(strsignal(WSTOPSIG(status)));
      Sio_puts("\n");

      Sigprocmask(SIG_BLOCK, &mask_all, &prev_all);
      SetStatus(FindJobByPid(pid), false);
      Sigprocmask(SIG_SETMASK, &prev_all, NULL);
    } else if (WIFCONTINUED(status)) {
      SetFgPid(pid);

      Sigprocmask(SIG_BLOCK, &mask_all, &prev_all);
      SetStatus(FindJobByPid(pid), true);
      Sigprocmask(SIG_SETMASK, &prev_all, NULL);
    }
  }

  errno = old_errno;
}

void HandlerSigint(int sig) {
  if (NoOtherProcess()) {
    Signal(SIGINT, SIG_DFL);
    Kill(getpid(), SIGINT);
  } else {
    Kill(GetFgPid(), SIGINT);
  }
}

void HandlerSigtstp(int sig) {
  if (NoOtherProcess()) {
    Signal(SIGTSTP, SIG_DFL);
    Kill(getpid(), SIGTSTP);
  } else {
    Kill(GetFgPid(), SIGTSTP);
  }
}
