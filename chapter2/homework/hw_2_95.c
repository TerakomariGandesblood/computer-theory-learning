//
// Created by kaiser on 18-10-11.
//

#include "../config.h"

float_bits float_half(float_bits f) {
  unsigned frac = f & 0x7fffff;
  unsigned exp = (f >> 23) & 0xff;
  unsigned sign = f >> 31;

  if (exp == 0xff)
    return f;

  int carry = ((frac & 0x3) == 0x3);

  if (exp == 0) {
    frac >>= 1;
    frac += carry;
  } else if (exp == 1) {
    exp = 0;
    frac = (frac >> 1) | (1 << 22);
    frac += carry;
  } else {
    exp -= 1;
  }

  return (sign << 31) | (exp << 23) | frac;
}