//
// Created by kaiser on 18-10-11.
//

#include <stdlib.h>
#include <string.h>

void *my_calloc(size_t nmenb, size_t size) {
  if (nmenb == 0 || size == 0) return NULL;
  size_t buf_size = nmenb * size;
  if (nmenb != buf_size / size) return NULL;
  void *ret = malloc(buf_size);
  return memset(ret, 0, buf_size);
}