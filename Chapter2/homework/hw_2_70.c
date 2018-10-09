//
// Created by kaiser on 18-10-9.
//

int fits_bits(int x, int n) {
    int low = -(1 << (n - 1));
    int high = (1 << (n - 1)) - 1;
    return (x >= low) && (x <= high);
}