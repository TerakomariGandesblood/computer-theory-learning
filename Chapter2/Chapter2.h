//
// Created by kaiser on 18-9-29.
//

#ifndef CHAPTER2_CHAPTER2_H
#define CHAPTER2_CHAPTER2_H

#include <stddef.h>

typedef const unsigned char *byte_pointer;

void show_byte(byte_pointer start, size_t len);

void show_byte_short(short x);

void show_byte_long(long x);

void show_byte_double(double x);

void show_binary(byte_pointer start, size_t len);

void show_binary_float(float x);

void show_binary_double(double x);

#endif //CHAPTER2_CHAPTER2_H
