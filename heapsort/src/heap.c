#include <math.h>
#include <stdio.h>
#include "heap.h"

static void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

static int left_index(int index) {
  return (2 * index) + 1;
}

static int right_index(int index) {
  return (2 * index) + 2;
}

static void max_heapify(int *array, int heap_size, int index) {
  int largest_index = index;

  int li = left_index(index);
  if (li <= heap_size && array[largest_index] < array[li]) {
    largest_index = li;
  }

  int ri = right_index(index);
  if (ri <= heap_size && array[largest_index] < array[ri]) {
    largest_index = ri;
  }

  if (largest_index != index) {
    swap(&array[index], &array[largest_index]);
    max_heapify(array, heap_size, largest_index);
  }
}

static void build_heap(int *array, int array_length, int heap_size) {
  int last_subroot_index = (array_length / 2) - 1;
  while (last_subroot_index > -1) {
    max_heapify(array, heap_size, last_subroot_index--);
  }
}

void heapsort(int *array, int array_length) {
  int heap_size = array_length - 1;
  build_heap(array, array_length, heap_size);

  while (heap_size > 0) {
    swap(&array[0], &array[heap_size]);
    max_heapify(array, --heap_size, 0);
  }
}
