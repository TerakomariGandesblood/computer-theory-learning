//
// Created by kaiser on 18-10-7.
//

#include <limits.h>
#include <stdbool.h>

bool int_shifts_are_arithmetic(void) {
    int text = (~0) >> 1;
    return text != INT_MAX;
}