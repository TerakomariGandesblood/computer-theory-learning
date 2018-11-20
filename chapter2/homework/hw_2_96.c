//
// Created by kaiser on 18-10-11.
//

#include "../config.h"
#include <limits.h>

int float_f2i(float_bits f)
{
    unsigned frac = f & 0x7fffff;
    unsigned exp = (f >> 23) & 0xff;
    unsigned bias = 127;
    int ret;

    if (exp < 0 + bias)
        ret = 0;
    if (exp == 0xff || exp >= 31 + bias)
        ret = INT_MIN;
    else
    {
        int E = exp - bias;
        int M = frac | 0x800000;
        if (E > 23)
            ret = M << (E - 23);
        else
            ret = M >> (23 - E);
    }

    return (f >> 31) ? -ret : ret;
}