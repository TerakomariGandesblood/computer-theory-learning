//
// Created by kaiser on 18-9-29.
//

#include "config.h"
#include <stdio.h>
#include <limits.h>

void show_binary(byte_pointer start, size_t len) {
    for (size_t i = len; i-- > 0;) {
        unsigned char byte = start[i];

        int temp[CHAR_BIT];
        for (size_t j = CHAR_BIT; j-- > 0; byte >>= 1)
            temp[j] = 1U & byte;

        for (size_t index = 0; index < CHAR_BIT; ++index) {
            printf("%d", temp[index]);
        }
        printf(" ");
    }
    printf("\n");
}

void show_binary_short(short x) {
    show_binary((byte_pointer) &x, sizeof(x));
}

void show_binary_int(int x) {
    show_binary((byte_pointer) &x, sizeof(x));
}

void show_binary_unsigned(unsigned x) {
    show_binary((byte_pointer) &x, sizeof(x));
}

void show_binary_long(long x) {
    show_binary((byte_pointer) &x, sizeof(x));
}

void show_binary_long_long(long long x) {
    show_binary((byte_pointer) &x, sizeof(x));
}

void show_binary_unsigned_long_long(unsigned long long x) {
    show_binary((byte_pointer) &x, sizeof(x));
}

void show_binary_float(float x) {
    byte_pointer start = (byte_pointer) &x;
    size_t len = sizeof(x);

    int count = 0;
    for (size_t i = len; i-- > 0;) {
        unsigned char byte = start[i];

        int temp[CHAR_BIT];
        for (size_t j = CHAR_BIT; j-- > 0; byte >>= 1)
            temp[j] = 1U & byte;

        for (size_t index = 0; index < CHAR_BIT; ++index) {
            printf("%d", temp[index]);
            ++count;
            if (count == 1 || count == 1 + 8 || count == 1 + 8 + 23)
                printf(" ");
        }
    }
    printf("\n");
}

void show_binary_double(double x) {
    byte_pointer start = (byte_pointer) &x;
    size_t len = sizeof(x);

    int count = 0;
    for (size_t i = len; i-- > 0;) {
        unsigned char byte = start[i];

        int temp[CHAR_BIT];
        for (size_t j = CHAR_BIT; j-- > 0; byte >>= 1)
            temp[j] = 1U & byte;

        for (size_t index = 0; index < CHAR_BIT; ++index) {
            printf("%d", temp[index]);
            ++count;
            if (count == 1 || count == 1 + 11 || count == 1 + 11 + 52)
                printf(" ");
        }
    }
    printf("\n");
}