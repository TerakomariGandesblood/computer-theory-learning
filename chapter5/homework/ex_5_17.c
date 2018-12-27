//
// Created by kaiser on 18-12-5.
//

#include <stddef.h>

void *basic_memset(void *s, int c, size_t n) {
  size_t cnt = 0;
  unsigned char *schar = s;
  while (cnt < n) {
    *schar++ = (unsigned char)c;
    cnt++;
  }
  return s;
}

void *effective_memset(void *s, unsigned long c, size_t n) {
  unsigned char *schar = s;
  size_t i;

  for (i = 0; i < n && (unsigned long)s % sizeof(unsigned long) != 0; i++) {
    *schar++ = (unsigned char)c;
  }

  for (; i + 7 < n; i += 8) {
    *(unsigned long *)schar = c;
    schar += 8;
  }

  for (; i < n; i++) {
    *schar++ = (unsigned char)c;
  }
  return s;
}