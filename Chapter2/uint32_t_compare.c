//
// Created by kaiser on 18-10-9.
//

#include <stdint.h>

int uint32_t_compare(uint32_t x, uint32_t y) {
    uint32_t diff = x ^y;
    if (!diff)
        return 0;
    int count = 0;

    diff |= diff >> 1;
    diff |= diff >> 2;
    diff |= diff >> 4;
    diff |= diff >> 8;
    diff |= diff >> 16;
    diff ^= diff >> 1;

    return x & diff ? -1 : 1;
}