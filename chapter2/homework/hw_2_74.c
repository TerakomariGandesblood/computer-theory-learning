//
// Created by kaiser on 18-10-10.
//

#include <limits.h>
#include <stdbool.h>

int tsub_ok(int x, int y) {
    int sub = x - y;
    bool pos_overflow = !(x & INT_MIN) && (y & INT_MIN) && (sub & INT_MIN);
    bool neg_overflow = (x & INT_MIN) && !(y & INT_MIN) && !(sub & INT_MIN);
    return !pos_overflow && !neg_overflow;
}