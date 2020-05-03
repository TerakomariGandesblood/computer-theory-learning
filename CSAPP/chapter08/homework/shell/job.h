//
// Created by kaiser on 19-4-22.
//

#ifndef CSAPP_CHAPTER8_HOMEWORK_SHELL_JOB_H_
#define CSAPP_CHAPTER8_HOMEWORK_SHELL_JOB_H_

#include <stdbool.h>

#include "csapp.h"

#define MAXJOBS 128

typedef int Jid;

typedef struct {
  Jid jid;
  pid_t pid;
  bool is_run;
  char cmdline[MAXLINE];
} Job;

bool IsFgPid(pid_t pid);
pid_t GetFgPid();
void SetFgPid(pid_t pid);

void PrintJobs();
int AddJob(pid_t pid, const char *cmdline);
void DeleteJob(pid_t pid);

Job *FindJobByPid(pid_t pid);
Job *FindJobByJid(Jid jid);

void SetStatus(Job *jp, bool is_run);

void HandlerSigchld(int sig);
void HandlerSigint(int sig);
void HandlerSigtstp(int sig);

#endif  // CSAPP_CHAPTER8_HOMEWORK_SHELL_JOB_H_
