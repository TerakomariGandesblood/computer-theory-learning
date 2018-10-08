//
// Created by kaiser on 18-10-7.
//

unsigned srl(unsigned x, int k) {
    unsigned xsra = (unsigned) ((int) x >> k);
    unsigned temp = ~0U;
    temp >>= k;
    return xsra & temp;
}

int sra(int x, int k) {
    int xsrl = (int) ((unsigned) x >> k);
    int temp = ~0;
    temp >>= k;
    return xsrl | temp;
}