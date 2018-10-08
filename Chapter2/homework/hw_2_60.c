//
// Created by kaiser on 18-10-7.
//

#include "../config.h"

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    ((byte_pointer) &x)[i] = b;
    return x;
}