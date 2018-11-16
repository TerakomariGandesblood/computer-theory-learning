//
// Created by kaiser on 18-11-16.
//

#include "../config.h"

range_t find_range(float x) {
    __asm__(
    "vxorps %xmm1,%xmm1,%xmm1;"
    "vucomiss %xmm1,%xmm0;"
    "jb L0;"
    "je L1;"
    "ja L2;"
    "jmp L3;"
    "L0:;"
    "movq $0,%rax;"
    "jmp L5;"
    "L1:;"
    "movq $1,%rax;"
    "jmp L5;"
    "L2:;"
    "movq $2,%rax;"
    "jmp L5;"
    "L3:;"
    "movq $4,%rax;"
    "jmp L5;"
    "L5:;"
    "ret;"
    );
}