//
// Created by kaiser on 18-9-29.
//

#include "Chapter2.h"
#include <stdio.h>
#include <limits.h>

void show_binary(byte_pointer start, size_t len) {
    for (size_t i = len; i-- > 0;) {
        unsigned char byte = start[i];

        size_t size = sizeof(byte) * CHAR_BIT;
        int temp[size];
        for (size_t j = size; j-- > 0; byte >>= 1)
            temp[j] = 1U & byte;

        for (size_t index = 0; index < size; ++index) {
            printf("%d", temp[index]);
        }
        printf(" ");
    }
    printf("\n");
}

void show_binary_float(float x) {
    byte_pointer start = (byte_pointer) &x;
    size_t len = sizeof(x);

    int count = 0;
    for (size_t i = len; i-- > 0;) {
        unsigned char byte = start[i];

        size_t size = sizeof(byte) * CHAR_BIT;
        int temp[size];
        for (size_t j = size; j-- > 0; byte >>= 1)
            temp[j] = 1U & byte;

        for (size_t index = 0; index < size; ++index) {
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

        size_t size = sizeof(byte) * CHAR_BIT;
        int temp[size];
        for (size_t j = size; j-- > 0; byte >>= 1)
            temp[j] = 1U & byte;

        for (size_t index = 0; index < size; ++index) {
            printf("%d", temp[index]);
            ++count;
            if (count == 1 || count == 1 + 11 || count == 1 + 11 + 52)
                printf(" ");
        }
    }
    printf("\n");
}