//
// Created by kaiser on 18-10-7.
//

unsigned hw_2_59(unsigned x, unsigned y) {
  return (x & 0xff) | (y & ~0xff);
}