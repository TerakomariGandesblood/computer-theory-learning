//
// Created by kaiser on 18-10-7.
//

#include "../config.h"
#include <stdbool.h>

bool is_little_endian(void) {
    int test = 0xff;
    if (*((byte_pointer) &test) == 0xff)
        return true;
    else
        return false;
}