#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define _MAX_LINE_READ_BUFFER 128

unsigned int my_stoi(char *str) {
  int res, i, d;
  char c;

  res = 0;
  i = my_strlen(str) - 1;
  while ((c = *str++) != '\0') {
    if (!(c >= '0' && c <= '9')) {
      fprintf(stderr, "Invalid integer character: %c\n", c);
      exit(EXIT_FAILURE);
    }

    d = c - '0';
    res = res + (d * my_pow(10, i));
    --i;
  }

  return res;
}

unsigned int my_pow(int base, int exponent) {
  if (exponent == 0) return 1;

  int res = 1;
  int i = 0;
  while (i < exponent) {
    res = res * base;
    ++i;
  }
  return res;
}

unsigned int my_strlen(char *str) {
  int i = 0;
  while(*str++ != '\0')
    i++;
  return i;
}

unsigned int readint() {
  char c, str[_MAX_LINE_READ_BUFFER];
  int i = 0;

  while ((c = getchar()) != EOF && c != '\n' && i < _MAX_LINE_READ_BUFFER) {
    str[i++] = c;
  }
  str[i] = '\0';

  return my_stoi(str);
}
