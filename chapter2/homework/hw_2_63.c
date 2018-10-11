//
// Created by kaiser on 18-10-7.
//

#include "../config.h"

unsigned srl(unsigned x, int k) {
    unsigned xsra = (unsigned) ((int) x >> k);
    return xsra & ((~0U) >> k);
}

int sra(int x, int k) {
    int xsrl = (int) ((unsigned) x >> k);
    int neg = (x >> (INT_BIT - 1)) & 1;
    return xsrl | ((neg << (INT_BIT - 1)) >> k);
}