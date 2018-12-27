//
// Created by kaiser on 18-10-9.
//

#include "../config.h"

int fits_bits(int x, int n) { return !((x >> (n - 1)) >> 1); }