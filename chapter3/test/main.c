// long swap_add(long *xp, long *yp) {
//     long x = *xp;
//     long y = *yp;
//     *xp = x;
//     *yp = y;
//     return x + y;
// }

// long caller() {
//     long arg1 = 534;
//     long arg2 = 1057;
//     long sum = swap_add(&arg1, &arg2);
//     long diff = arg1 - arg2;
//     return sum * diff;
// }

void proc(long a, long *pa, int b, int *pb,
          short c, short *pc, char d, char *pd) {
    *pa = d;
    *pb = c;
    *pc = b;
    *pd = a;
}

long call_proc() {
    long x1 = 1;
    int x2 = 2;
    short x3 = 3;
    char x4 = 4;
    proc(x1, &x1, x2, &x2, x3, &x3, x4, &x4);
    return (x1 + x2) * (x3 - x4);
}

int main() {
    call_proc();
}