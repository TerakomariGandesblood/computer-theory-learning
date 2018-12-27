//
// Created by kaiser on 18-11-16.
//

#include <stdbool.h>
#include <stdio.h>

void good_echo() {
  char buf[2];

  while (true) {
    char *ret = fgets(buf, 2, stdin);
    if (ret == NULL) break;
    printf("%s", buf);
  }
}