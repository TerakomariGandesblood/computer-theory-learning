//
// Created by kaiser on 19-4-2.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *p = malloc(32);
  free(p);
}
