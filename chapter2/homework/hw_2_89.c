//
// Created by kaiser on 18-10-16.
//

#include <stdbool.h>

//true
bool hw_2_89_a(int x, double dx) {
  return (float) x == (float) dx;
}

//false x-y可能溢出
bool hw_2_89_b(double dx, double dy, int x, int y) {
  return dx - dy == (double) (x - y);
}

//right
bool hw_2_89_c(double dx, double dy, double dz) {
  return (dx + dy) + dz == dx + (dy + dz);
}

//false dx*dy可能出现不能准确表示的结果
bool hw_2_89_d(double dx, double dy, double dz) {
  return (dx * dy) * dz == dx * (dy * dz);
}

//false dx=0
bool hw_2_89_e(double dx, double dz) {
  return dx / dx == dz / dz;
}