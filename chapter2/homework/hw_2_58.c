//
// Created by kaiser on 18-10-7.
//

#include <stdbool.h>
#include "../config.h"

bool is_little_endian(void) {
  unsigned test = 0xff;
  return *((byte_pointer)&test) == 0xff;
}