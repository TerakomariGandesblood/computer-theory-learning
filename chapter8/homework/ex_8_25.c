//
// Created by kaiser on 19-4-22.
//

#include "csapp.h"

sigjmp_buf buf;

void handler(int sig) { siglongjmp(buf, 1); }

char *tfgets(char *s, int n, FILE *stream) {
  char *ret;
  if (!sigsetjmp(buf, 1)) {
    Alarm(2);
    Signal(SIGALRM, handler);
    ret = fgets(s, n, stream);
  } else {
    ret = NULL;
  }

  Signal(SIGALRM, SIG_DFL);
  return ret;
}

int main(void) {
  char s[MAXBUF];
  char *ss = tfgets(s, MAXBUF, stdin);

  if (ss == NULL) {
    printf("nothing\n");
  } else {
    printf("%s\n", s);
  }
}
