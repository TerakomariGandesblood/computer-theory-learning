//
// Created by kaiser on 19-4-22.
//

#ifndef CSAPP_CHAPTER8_HOMEWORK_SHELL_SHELL_H_
#define CSAPP_CHAPTER8_HOMEWORK_SHELL_SHELL_H_

#include <stdbool.h>

#define MAXARGS 128

void Eval(char *cmdline);
bool ParseLine(char *buf, char *argv[]);
bool BuiltinCommand(char *argv[]);

void BuiltinBg(char *argv[]);
void BuiltinFg(char *argv[]);

#endif  // CSAPP_CHAPTER8_HOMEWORK_SHELL_SHELL_H_
