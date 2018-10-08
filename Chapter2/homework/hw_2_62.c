//
// Created by kaiser on 18-10-7.
//

#include <stdbool.h>
#include <limits.h>

bool int_shifts_are_arithmetic() {
    int text = ~0;
    text >>= 1;
    if (((text >> (sizeof(int) * CHAR_BIT - 1)) & 1) == 1)
        return true;
    else
        return false;
}