//
// Created by kaiser on 18-10-10.
//

#include "../config.h"

int xbyte(packed_t word, int bytenum)
{
    int left = (sizeof(int) - bytenum - 1) << 3;
    return (word << left) >> 24;
}