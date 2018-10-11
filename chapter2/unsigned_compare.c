//
// Created by kaiser on 18-10-9.
//

int unsigned_compare(unsigned x, unsigned y) {
    unsigned diff = x ^y;
    if (!diff)
        return 0;

    diff |= diff >> 1;
    diff |= diff >> 2;
    diff |= diff >> 4;
    diff |= diff >> 8;
    diff |= diff >> 16;
    diff ^= diff >> 1;

    return x & diff ? -1 : 1;
}