//
// Created by kaiser on 18-10-8.
//

#include "../config.h"
#include <stdbool.h>

int leftmost_one(unsigned x) {
    int count = 0;
    while (true) {
        if ((x >> (INT_BIT - 1)) == 1)
            break;
        x <<= 1;
        ++count;
    }
    return 1 << (INT_BIT - 1 - count);
}