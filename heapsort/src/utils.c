#include "utils.h"
#include <stdio.h>

void print_int_array(int *array, unsigned int array_length) {
  unsigned int i;
  for (i = 0; i < array_length; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
