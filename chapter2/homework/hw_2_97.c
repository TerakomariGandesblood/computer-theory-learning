//
// Created by kaiser on 18-10-11.
//

#include "../config.h"
#include <limits.h>

int zero_count(int x) {
    int ret = 0;
    for (;; x <<= 1) {
        if ((x & 0x80000000) == 0)
            ++ret;
        else
            break;
    }
    return ret;
}

float_bits float_i2f(int i) {
    unsigned sign = i > 0 ? 0 : 1;
    if (i == 0)
        return 0;
    if (i == INT_MIN)
        return 0xcf000000;

    int M = i > 0 ? i : -i;
    int count = zero_count(M);

    int expr = 31 - count + 127;
    M &= ~(1 << (31 - count));

    if (count + 1 >= 9)
        M <<= (count + 1 - 9);
    else {
        if ((M & (1 << (9 - count - 1))) == (1 << (9 - count - 1)) &&
            (M & (1 << (9 - count - 1 - 1))) == (1 << (9 - count - 1 - 1))) {
            M >>= (9 - count - 1);
            M += 1;
        }
        if (zero_count(M) != count) {
            expr += 1;
            M &= 0x7fffff;
        }
    }

    return (sign << 31) | (expr << 23) | M;
}