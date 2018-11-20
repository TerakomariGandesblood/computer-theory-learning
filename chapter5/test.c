//
// Created by kaiser on 18-11-17.
//

#include "test.h"
#include <malloc.h>

vec_ptr new_vec(long len)
{
    vec_ptr result = (vec_ptr) malloc(sizeof(vec_rec));
    if (!result)
        return NULL;

    data_t *data = NULL;
    result->len = len;
    if (len > 0)
    {
        data = (data_t *) calloc(len, sizeof(data_t));
        if (!data)
        {
            free(result);
            return NULL;
        }
    }

    result->data = data;
    return result;
}

int get_vec_element(vec_ptr v, long index, data_t *dest)
{
    if (index < 0 || index >= v->len)
        return 0;
    *dest = v->data[index];
    return 1;
}

long vec_length(vec_ptr v)
{
    return v->len;
}

data_t *get_vec_start(vec_ptr v)
{
    return v->data;
}

void combine1(vec_ptr v, data_t *dest)
{
    *dest = IDENT;

    for (long i = 0; i < vec_length(v); i++)
    {
        data_t val;
        get_vec_element(v, i, &val);
        *dest = *dest OP val;
    }
}

void combine2(vec_ptr v, data_t *dest)
{
    *dest = IDENT;

    long length = vec_length(v);
    for (long i = 0; i < length; i++)
    {
        data_t val;
        get_vec_element(v, i, &val);
        *dest = *dest OP val;
    }
}

void combine3(vec_ptr v, data_t *dest)
{
    *dest = IDENT;
    long length = vec_length(v);
    data_t *data = get_vec_start(v);

    for (long i = 0; i < length; i++)
    {
        *dest = *dest OP data[i];
    }
}

void combine4(vec_ptr v, data_t *dest)
{
    data_t acc = IDENT;
    long length = vec_length(v);
    data_t *data = get_vec_start(v);

    for (long i = 0; i < length; i++)
    {
        acc = acc OP data[i];
    }
    *dest = acc;
}