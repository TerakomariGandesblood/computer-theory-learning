//
// Created by kaiser on 18-10-16.
//

#include <stdbool.h>

bool hw_2_89_a(int x, double dx) {
    return (float) x == (float) dx;
}

bool hw_2_89_b(double dx, double dy, int x, int y) {
    return dx - dy == (double) (x - y);
}

bool hw_2_89_c(double dx, double dy, double dz) {
    return (dx + dy) + dz == dx + (dy + dz);
}

bool hw_2_89_d(double dx, double dy, double dz) {
    return (dx * dy) * dz == dx * (dy * dz);
}

bool hw_2_89_e(double dx, double dz) {
    return dx / dx == dz / dz;
}