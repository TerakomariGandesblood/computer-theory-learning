//
// Created by kaiser on 18-9-29.
//

#ifndef CHAPTER2_CHAPTER2_H
#define CHAPTER2_CHAPTER2_H

#include "config.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

//2.55
void show_byte(byte_pointer start, size_t len);

//2.57
void show_byte_short(short x);

void show_byte_long(long x);

void show_byte_double(double x);

//2.58
bool is_little_endian();

//2.59
uint32_t hw_2_59(uint32_t x, uint32_t y);

//2.60
unsigned replace_byte(unsigned x, int i, unsigned char b);

//2.61
bool hw_2_61_a(int x);

bool hw_2_61_b(int x);

bool hw_2_61_c(int x);

bool hw_2_61_d(int x);

//2.62
bool int_shifts_are_arithmetic();

//2.63
unsigned srl(unsigned x, int k);

int sra(int x, int k);

//mine
void show_binary(byte_pointer start, size_t len);

void show_binary_float(float x);

void show_binary_double(double x);

#endif //CHAPTER2_CHAPTER2_H
