//
// Created by kaiser on 18-10-10.
//

#include "../config.h"

int signed_high_prod(int x, int y) {
    long long ret = (long long) x * (long long) y;
    return (int) (ret >> 32);
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    int x_high = x >> (INT_BIT - 1);
    int y_high = y >> (INT_BIT - 1);
    return signed_high_prod(x, y) + x_high * y + y_high * x;
}
