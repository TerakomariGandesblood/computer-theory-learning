//
// Created by kaiser on 18-12-5.
//

#ifndef CHAPTER5_VEC_H
#define CHAPTER5_VEC_H

typedef double data_t;

typedef struct {
    long len;
    data_t *data;
} vec_rec, *vec_ptr;

vec_ptr new_vec(long len);

long vec_length(vec_ptr v);

data_t *get_vec_start(vec_ptr v);

#endif //CHAPTER5_VEC_H
