//
// Created by kaiser on 18-12-5.
//

#ifndef CSAPP_CHAPTER5_H
#define CSAPP_CHAPTER5_H

#include "vec.h"
#include <stddef.h>

//5.13
void inner4(vec_ptr u, vec_ptr v, data_t *dest);

//5.14
void inner5(vec_ptr u, vec_ptr v, data_t *dest);

//5.15
void inner6(vec_ptr u, vec_ptr v, data_t *dest);

//5.16
void inner7(vec_ptr u, vec_ptr v, data_t *dest);

//5.17
void *basic_memset(void *s, int c, size_t n);

void *effective_memset(void *s, unsigned long c, size_t n);

//5.18
double poly(double a[], double x, long degree);

double polyh(double a[], double x, long degree);

double poly_6_3a(double a[], double x, long degree);

//5.19
void psum1a(float a[], float p[], long n);

void psum4_1a(float a[], float p[], long n);

#endif //CSAPP_CHAPTER5_H
