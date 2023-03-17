#include <stdio.h>
#include <stdlib.h>

unsigned int readline(char *line_buf, unsigned int max_line_buffer_length) {
  char c;
  unsigned int i = 0;

  while ((c = getchar()) != EOF && c != '\n') {
    if (++i >= max_line_buffer_length) return i;
    line_buf[i - 1] = c;
  }

  if (c == EOF) return EOF;

  line_buf[i] = '\0';
  

  return i;
}
