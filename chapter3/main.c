// #include <stdio.h>

// void multstore(long x, long y, long *dest);

// int main() {
//     long d;
//     multstore(2, 3, &d);
//     printf("2*3 --> %ld\n", d);
// }

// long mult2(long a, long b) {
//     long s = a * b;
//     return s;
// }

#include <stdio.h>

int main(void) {
    long a = 10000000000000, b = 20000000;
    long c = a * b;
    printf("%ld", c);
}