//
// Created by kaiser on 18-10-7.
//

#include <limits.h>
#include <stdbool.h>

bool hw_2_61_a(int x) { return !(x + 1); }

bool hw_2_61_b(int x) { return !x; }

bool hw_2_61_c(int x) { return !(((x & 0xff) + 1) & 0xff); }

bool hw_2_61_d(int x) {
  return !((((x >> (sizeof(int) - 1) * CHAR_BIT) & 0xff) + 1) & 0xff);
}