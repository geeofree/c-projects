#include <stdio.h>
#include <stdlib.h>
#define LEN(array) (sizeof(array))/(sizeof(array[0]))
#define MAX_NUMBERS 10

int partition(int *array, int start_index, int end_index);
void quicksort(int *array, int start_index, int end_index);
void swap(int *a, int *b);

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <number>[numbers...]\n", argv[0]);
    return 1;
  }

  if (argc - 1 > MAX_NUMBERS) {
    fprintf(stderr, "Too many number arguments. Maximum is %d, total numbers given is %d.\n", MAX_NUMBERS, argc - 1);
    return 1;
  }

  int nums[MAX_NUMBERS];
  int i;

  for (i = 1; i < argc; i++) {
    nums[i - 1] = atoi(argv[i]);
  }

  printf("Input:\n");
  for (i = 0; i < argc - 1; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n\n");

  quicksort(nums, 0, argc - 2);
  printf("Sorted:\n");
  for (i = 0; i < argc - 1; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  return 0;
}

void quicksort(int *array, int start_index, int end_index) {
  if (start_index < end_index) {
    int q = partition(array, start_index, end_index);
    quicksort(array, start_index, q - 1);
    quicksort(array, q + 1, end_index);
  }
}

int partition(int *array, int start_index, int end_index) {
  int pivot = array[end_index];
  int i = start_index - 1;

  int j;
  for (j = start_index; j <= end_index - 1; j++) {
    if (array[j] <= pivot) {
      i += 1;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[end_index]);
  return i + 1;
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
