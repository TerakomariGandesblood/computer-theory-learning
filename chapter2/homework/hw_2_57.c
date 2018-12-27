//
// Created by kaiser on 18-10-7.
//

#include "../chapter2.h"
#include "../config.h"

void show_byte_short(short x) { show_byte((byte_pointer)&x, sizeof(x)); }

void show_byte_int(int x) { show_byte((byte_pointer)&x, sizeof(x)); }

void show_byte_long(long x) { show_byte((byte_pointer)&x, sizeof(x)); }

void show_byte_long_long(long long x) {
  show_byte((byte_pointer)&x, sizeof(x));
}

void show_byte_float(float x) { show_byte((byte_pointer)&x, sizeof(x)); }

void show_byte_double(double x) { show_byte((byte_pointer)&x, sizeof(x)); }
