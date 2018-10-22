#include <stdio.h>

int main() {
    __asm__(
    "movb $0xf,(%ebx);");
    printf("%ld\n");
}