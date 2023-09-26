#ifndef _MEM_H
#define _MEM_H
#include <stddef.h>
void* memalloc(size_t block_size);
void* memrealloc(void* ptr, size_t block_size);
#endif
