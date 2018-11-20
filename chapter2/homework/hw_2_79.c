//
// Created by kaiser on 18-10-11.
//

#include "../chapter2.h"

int mul3div4(int x)
{
    int temp = x + (x << 1);
    return divide_power2(temp, 2);
}