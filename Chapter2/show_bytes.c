//
// Created by kaiser on 18-9-29.
//

#include "Chapter2.h"
#include <stdio.h>

void show_byte(byte_pointer start, size_t len) {
    for (size_t i = len; i-- > 0;) {
        printf("%.2hhx ", start[i]);
    }
    printf("\n");
}

void show_byte_short(short x) {
    show_byte((byte_pointer) &x, sizeof(x));
}

void show_byte_long(long x) {
    show_byte((byte_pointer) &x, sizeof(x));
}

void show_byte_double(double x) {
    show_byte((byte_pointer) &x, sizeof(x));
}
