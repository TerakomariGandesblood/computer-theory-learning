//
// Created by kaiser on 18-10-7.
//

#include <stdbool.h>

bool hw_2_61_a(int x) {
    return !(x + 1);
}

bool hw_2_61_b(int x) {
    return !x;
}

bool hw_2_61_c(int x) {
    return !(((x & 0xff) + 1) & 0xff);
}

bool hw_2_61_d(int x) {
    return !((((x >> 24) & 0xff) + 1) & 0xff);
}