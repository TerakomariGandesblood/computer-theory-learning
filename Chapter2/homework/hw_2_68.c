//
// Created by kaiser on 18-10-8.
//

#include "../config.h"

int low_one_mask(int n) {
    unsigned ret = ~0U;
    return (int) (ret >> (INT_BIT - n));
}