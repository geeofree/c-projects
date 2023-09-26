#include "mem.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* memalloc(size_t block_size) {
  void* mem = malloc(block_size);

  if (mem == NULL) {
    fprintf(stderr, "Could not allocate memory: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  return mem;
}

void* memrealloc(void* ptr, size_t block_size) {
  void* mem = realloc(ptr, block_size);

  if (mem == NULL) {
    fprintf(stderr, "Could not reallocate memory: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  return mem;
}
