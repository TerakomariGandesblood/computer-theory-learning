//
// Created by kaiser on 18-10-7.
//

#include "../config.h"
#include <stdbool.h>

unsigned srl(unsigned x, int k) {
    unsigned xsra = (unsigned) ((int) x >> k);
    unsigned temp = ~0U;
    temp >>= k;
    return xsra & temp;
}

int sra(int x, int k) {
    int xsrl = (int) ((unsigned) x >> k);
    int neg = (x >> (INT_BIT - 1)) & 1;
    if (neg == 0)
        return xsrl;
    else
        return xsrl | ((neg << (INT_BIT - 1)) >> k);
}