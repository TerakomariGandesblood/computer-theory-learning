//
// Created by kaiser on 18-10-11.
//

#include "../config.h"

float_bits float_twice(float_bits f)
{
    unsigned frac = f & 0x7fffff;
    unsigned exp = (f >> 23) & 0xff;
    unsigned sign = f >> 31;

    if (exp == 0xff)
        return f;

    if (exp == 0)
    {
        if ((frac >> 22) == 1)
        {
            exp = 1;
            frac <<= 1;
            frac &= 0x7fffff;
        }
        else
        {
            frac <<= 1;
        }
    }
    else if (exp + 1 == 0xff)
    {
        exp = 0xff;
        frac = 0;
    }
    else
    {
        exp += 1;
    }

    return (sign << 31) | (exp << 23) | frac;
}