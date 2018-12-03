//
// Created by kaiser on 18-11-18.
//

#include "test.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    vec_ptr fuck = new_vec(100000000);
    long shit;

    {
        clock_t start = clock();
        combine1(fuck, &shit);
        printf("%ld\n", clock() - start);
    }
    {
        clock_t start = clock();
        combine2(fuck, &shit);
        printf("%ld\n", clock() - start);
    }
    {
        clock_t start = clock();
        combine3(fuck, &shit);
        printf("%ld\n", clock() - start);
    }
    {
        clock_t start = clock();
        combine4(fuck, &shit);
        printf("%ld\n", clock() - start);
    }
    {
        clock_t start = clock();
        combine5(fuck, &shit);
        printf("%ld\n", clock() - start);
    }
    {
        clock_t start = clock();
        combine6(fuck, &shit);
        printf("%ld\n", clock() - start);
    }
    {
        clock_t start = clock();
        combine7(fuck, &shit);
        printf("%ld\n", clock() - start);
    }
}