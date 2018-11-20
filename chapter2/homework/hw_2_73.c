//
// Created by kaiser on 18-10-10.
//

#include <limits.h>
#include <stdbool.h>

int saturating_add(int x, int y)
{
    int sum = x + y;
    bool pos_overflow = !(x & INT_MIN) && !(y & INT_MIN) && (sum & INT_MIN);
    bool neg_overflow = (x & INT_MIN) && (y & INT_MIN) && !(sum & INT_MIN);
    ((!pos_overflow) || (sum = INT_MAX)) && ((!neg_overflow) || (sum = INT_MIN));
    return sum;
}