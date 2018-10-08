//
// Created by kaiser on 18-9-29.
//

#include "Chapter2.h"
#include <stdio.h>

int main() {
    int num = 100;
    show_byte((byte_pointer) &num, sizeof(num));
    show_byte_short(100);
    show_byte_long(100L);
    show_byte_double(100.0);
    printf("\n");

    show_binary((byte_pointer) &num, sizeof(num));
    show_binary_float(100.0f);
    show_binary_double(100.0);
    printf("\n");

    printf("%s\n", is_little_endian() ? "little endian" : "big endian");
    printf("\n");

    uint32_t num_hw_2_59 = hw_2_59(0x89ABCDEFU, 0x76543210U);
    show_byte((byte_pointer) &num_hw_2_59, sizeof(num_hw_2_59));
    printf("\n");

    unsigned num_rep_byte = replace_byte(0x12345678, 2, 0xab);
    show_byte((byte_pointer) &num_rep_byte, sizeof(num_rep_byte));
    printf("\n");

    printf("%s\n", hw_2_61_a(0xffffffff) ? "true" : "false");
    printf("%s\n", hw_2_61_b(0) ? "true" : "false");
    printf("%s\n", hw_2_61_c(0xabff) ? "true" : "false");
    printf("%s\n", hw_2_61_d(0xff000000) ? "true" : "false");
    printf("\n");

    printf("%s\n", int_shifts_are_arithmetic() ? "true" : "false");
    printf("\n");
}