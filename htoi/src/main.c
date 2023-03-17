#include <stdio.h>
#include "htoi.h"
#include "utils.h"

#define _MAX_LINE_BUFFER_LENGTH 128

int main() {
  char str_buffer[_MAX_LINE_BUFFER_LENGTH];
  printf("Enter a hex string: ");
  readline(str_buffer, _MAX_LINE_BUFFER_LENGTH);
  unsigned int res = htoi(str_buffer);
  printf("%s = %d\n", str_buffer, res);
  return 0;
}
