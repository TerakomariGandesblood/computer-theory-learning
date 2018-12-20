//
// Created by kaiser on 18-10-10.
//

#include <string.h>
#include <stddef.h>

void copy_int(int val, void *buf, size_t maxbyte) {
  if (maxbyte >= sizeof(val))
    memcpy(buf, (void *) &val, sizeof(val));
}