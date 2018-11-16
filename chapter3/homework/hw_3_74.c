//
// Created by kaiser on 18-11-16.
//

#include "../config.h"

range_t find_range_cmov(float x) {
    __asm__(
    "movq $0,%r8;"
    "movq $1,%r9;"
    "movq $2,%r10;"
    "movq $3,%r11;"
    "vxorps %xmm1,%xmm1,%xmm1;"
    "vucomiss %xmm1,%xmm0;"
    "cmovb %r8,%rax;"
    "cmove %r9,%rax;"
    "cmova %r10,%rax;"
    "cmovp %r11,%rax;"
    );
}