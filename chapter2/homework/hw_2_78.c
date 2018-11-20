//
// Created by kaiser on 18-10-11.
//

#include <limits.h>

int divide_power2(int x, int k)
{
    int neg = x & INT_MIN;
    !neg || (x = x + (1 << k) - 1);
    return x >> k;
}