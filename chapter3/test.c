//
// Created by kaiser on 18-11-13.
//

#include "chapter3.h"
#include <assert.h>

int main(void) {
    range_t n = NEG, z = ZERO, p = POS, o = OTHER;
    assert(o == find_range(0.0 / 0.0));
    assert(n == find_range(-2.3));
    assert(z == find_range(0.0));
    assert(p == find_range(3.33));
}