//
// Created by kaiser on 18-9-29.
//

#include "chapter2.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main(void) {
    int x = rand();
    int y = rand();
    int z = rand();
    double dx = (double) x;
    double dy = (double) y;
    double dz = (double) z;

    printf("%x %x %x\n", x, y, z);

    assert(hw_2_89_a(x, dx));
    assert(!hw_2_89_b(0, (double) (int) 0, INT_MIN, (double) (int) INT_MIN));
    assert(hw_2_89_c(dx, dy, dz));
    /* magic number, brute force attack */
    assert(!hw_2_89_d((double) (int) 0x64e73387, (double) (int) 0xd31cb264, (double) (int) 0xd22f1fcd));
    assert(!hw_2_89_e(dx, (double) (int) 0));
}