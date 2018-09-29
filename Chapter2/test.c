//
// Created by kaiser on 18-9-29.
//

#include "Chapter2.h"

int main() {
    int num = 100;
    show_byte((byte_pointer) &num, sizeof(num));
    show_byte_short(100);
    show_byte_long(100L);
    show_byte_double(100.0);

    show_binary((byte_pointer) &num, sizeof(num));
    show_binary_float(100);
    show_binary_double(100.0);
}