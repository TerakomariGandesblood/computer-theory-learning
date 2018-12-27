//
// Created by kaiser on 18-10-11.
//

#include <limits.h>
#include "../chapter2.h"
#include "../config.h"

float_bits float_absval(float_bits f) {
  if (is_nan(f) || ((f >> 31) & 1) == 0) return f;
  return f ^ INT_MIN;
}