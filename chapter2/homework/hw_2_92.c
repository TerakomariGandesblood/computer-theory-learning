//
// Created by kaiser on 18-10-11.
//

#include "../config.h"
#include <limits.h>
#include <stdbool.h>

bool is_nan(float_bits f)
{
    if ((f & 0x7fffff) != 0 && ((f >> 23) & 0xff) == 0xff)
        return true;
    return false;
}

float_bits float_negate(float_bits f)
{
    if (is_nan(f))
        return f;
    return f ^ INT_MIN;
}