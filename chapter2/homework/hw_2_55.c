//
// Created by kaiser on 18-9-29.
//

#include <stddef.h>
#include <stdio.h>
#include "../config.h"

void show_byte(byte_pointer start, size_t len) {
  for (size_t i = len; i-- > 0;) printf("%.2hhx ", start[i]);
  printf("\n");
}
