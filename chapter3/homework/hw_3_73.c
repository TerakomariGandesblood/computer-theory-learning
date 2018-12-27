//
// Created by kaiser on 18-11-16.
//

#include "../config.h"

range_t find_range(float x) {
  __asm__(
      "vxorps %xmm1,%xmm1,%xmm1;"
      "vucomiss %xmm1,%xmm0;"
      "jp L3;"
      "jb L0;"
      "je L1;"
      "ja L2;"
      "L0:;"
      "movq $0,%rax;"
      "jmp L4;"
      "L1:;"
      "movq $1,%rax;"
      "jmp L4;"
      "L2:;"
      "movq $2,%rax;"
      "jmp L4;"
      "L3:;"
      "movq $3,%rax;"
      "jmp L4;"
      "L4:;");
}