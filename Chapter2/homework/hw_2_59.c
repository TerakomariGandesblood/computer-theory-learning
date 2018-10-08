//
// Created by kaiser on 18-10-7.
//

#include <stdint.h>

uint32_t hw_2_59(uint32_t x, uint32_t y) {
    return (x & 0xff) | (y & 0xffffff00);
}