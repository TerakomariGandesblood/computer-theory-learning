//
// Created by kaiser on 18-9-29.
//

#include "chapter2.h"
#include <stdio.h>
#include <assert.h>

int main(void) {
    assert(float_le(-0, +0));
    assert(float_le(+0, -0));
    assert(float_le(0, 3));
    assert(float_le(-4, -0));
    assert(float_le(-4, 4));
}