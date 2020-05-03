//
// Created by kaiser on 19-4-16.
//

#include "csapp.h"

jmp_buf buf;

int error1 = 1;
int error2 = 0;

void foo(void);
void bar(void);

int main(void) {
  switch (setjmp(buf)) {
    case 0:
      foo();
      break;
    case 1:
      printf("Detected an error1 condition in foo\n");
      break;
    case 2:
      printf("Detected an error2 condition in foo\n");
      break;
    default:
      printf("Unknown error condition in foo\n");
  }
}

void foo(void) {
  if (error1) {
    longjmp(buf, 1);
  }
  bar();
}

void bar(void) {
  if (error2) {
    longjmp(buf, 2);
  }
}
