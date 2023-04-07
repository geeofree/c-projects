#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "utils.h"

#define SIZE(array) (sizeof(array))/(sizeof(array[0]))

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s num1 num2 num3 ... numN\n", argv[0]);
    return 1;
  }

  if (argc > MAX_NUMBERS) {
    fprintf(stderr, "Too many numbers.\n");
    return 1;
  }

  int numbers[MAX_NUMBERS], i;
  for (i = 1; i < argc; i++) {
    numbers[i - 1] = atoi(argv[i]);
  }
  print_int_array(numbers, argc - 1);

  heapsort(numbers, argc - 1);
  print_int_array(numbers, argc - 1);

  return 0;
}
