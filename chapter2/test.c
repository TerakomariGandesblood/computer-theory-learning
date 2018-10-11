//
// Created by kaiser on 18-9-29.
//

#include "chapter2.h"
#include <stdio.h>
#include <limits.h>

int main(void) {
    show_binary_unsigned(unsigned_high_prod(UINT_MAX, UINT_MAX));
    show_binary_unsigned(UINT_MAX * UINT_MAX);
    show_binary_unsigned_long_long((unsigned long long) UINT_MAX *
                                   (unsigned long long) UINT_MAX);

    show_binary_int(signed_high_prod(INT_MAX, INT_MAX));
    show_binary_int(INT_MAX * INT_MAX);
    show_binary_long_long((long long) INT_MAX * (long long) INT_MAX);

}