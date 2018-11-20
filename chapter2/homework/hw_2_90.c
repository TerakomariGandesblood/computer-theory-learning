//
// Created by kaiser on 18-10-11.
//

#include <float.h>
#include <limits.h>

float u2f(unsigned x)
{
    return *(float *) &x;
}

float fpwr2(int x)
{
    unsigned exp, frac;
    unsigned u;

    if (x < -149)
    {
        exp = 0;
        frac = 0;
    }
    else if (x < -126)
    {
        exp = 0;
        frac = ((1U << 22) >> (-x - 126));
    }
    else if (x < 128)
    {
        exp = (unsigned) (x + 127);
        frac = 0;
    }
    else
    {
        exp = 255;
        frac = 0;
    }

    u = exp << 23 | frac;
    return u2f(u);
}