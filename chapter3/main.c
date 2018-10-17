#include <stdio.h>

int main() {
    __asm__(
    "movw $-12355555,%ax;"
    "movswq %ax,%rsi;");
    printf("%ld\n");
}