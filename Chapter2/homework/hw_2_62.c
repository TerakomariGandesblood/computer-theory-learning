//
// Created by kaiser on 18-10-7.
//

#include "../config.h"
#include <stdbool.h>

bool int_shifts_are_arithmetic(void) {
    int text = ~0;
    text >>= 1;
    if (((text >> (INT_BIT - 1)) & 1) == 1)
        return true;
    else
        return false;
}