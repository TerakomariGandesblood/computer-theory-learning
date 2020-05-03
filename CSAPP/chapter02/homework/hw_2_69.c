//
// Created by kaiser on 18-10-9.
//

#include "../config.h"

unsigned rotate_left(unsigned x, int n) {
  unsigned temp = (x >> (INT_BIT - n - 1)) >> 1;
  return (x << n) | temp;
}