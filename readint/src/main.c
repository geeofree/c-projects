#include <stdio.h>
#include "utils.h"

int main() {
  printf("Let's add two numbers:\n");

  printf("a = ");
  int a = readint();

  printf("b = ");
  int b = readint();

  printf("a + b = %d + %d = %d\n", a, b, a + b);
  return 0;
}
