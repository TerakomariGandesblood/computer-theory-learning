//
// Created by kaiser on 18-10-11.
//

#include <limits.h>

int threefourths(int x) {
  int high = x & ~0x3;
  int low = x & 0x3;

  int highd4 = high >> 2;
  int highd4m3 = (highd4 << 1) + highd4;

  int neg = x & INT_MIN;
  int lowm3 = (low << 1) + low;
  !neg || (lowm3 = lowm3 + (1 << 2) - 1);
  int lowm3d4 = lowm3 >> 2;

  return highd4m3 + lowm3d4;
}