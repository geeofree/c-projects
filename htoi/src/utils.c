#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void readline(char *str, unsigned int max_line_buffer_length) {
  char c;
  unsigned int i = 0;

  while ((c = getchar()) != EOF && c != '\n' && i < max_line_buffer_length) {
    str[i++] = c;
  }

  if (i >= max_line_buffer_length) {
    fprintf(stderr, "ERR: Input length exceeds max line buffer length");
    exit(EXIT_FAILURE);
  }

  str[i] = '\0';
}
