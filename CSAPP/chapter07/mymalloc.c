//
// Created by kaiser on 19-4-2.
//

#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

void *malloc(size_t size) {
  void *(*mallocp)(size_t);
  char *error;

  mallocp = dlsym(RTLD_NEXT, "malloc");
  if ((error = dlerror()) != NULL) {
    fputs(error, stderr);
    exit(1);
  }
  char *ptr = mallocp(size);
  fprintf(stderr, "malloc(%d)=%p\n", (int)size, ptr);
  return ptr;
}

void free(void *ptr) {
  void (*freep)(void *);
  char *error;

  if (!ptr) return;
  freep = dlsym(RTLD_NEXT, "free");
  if ((error = dlerror()) != NULL) {
    fputs(error, stderr);
    exit(1);
  }
  freep(ptr);
  fprintf(stderr, "free(%p)\n", ptr);
}
