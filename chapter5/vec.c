//
// Created by kaiser on 18-12-5.
//

#include "vec.h"
#include <malloc.h>

vec_ptr new_vec(long len) {
    vec_ptr result = (vec_ptr) malloc(sizeof(vec_rec));
    if (!result) {
        return NULL;
    }

    data_t *data = NULL;
    result->len = len;
    if (len > 0) {
        data = (data_t *) calloc(len, sizeof(data_t));
        if (!data) {
            free(result);
            return NULL;
        }
    }

    result->data = data;
    return result;
}

long vec_length(vec_ptr v) {
    return v->len;
}

data_t *get_vec_start(vec_ptr v) {
    return v->data;
}