//
// Created by kaiser on 18-10-8.
//

int leftmost_one(unsigned x) {
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  return x ^ (x >> 1);
}