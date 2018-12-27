//
// Created by kaiser on 18-10-11.
//

#include "../config.h"

unsigned hw_2_81_a(int k) {
  unsigned ret = ~0U;
  return ret << k;
}

unsigned hw_2_81_b(int j, int k) { return ~hw_2_81_a(k) << j; }