#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "htoi.h"

unsigned int htoi(char *str) {
  if (!(*str++ == '0' && *str++ == 'x')) {
    str -= 1;
    fprintf(stderr, "Hex strings should start with '0x' received: %s\n", str);
    exit(EXIT_FAILURE);
  }

  char c;
  unsigned int res, d, i;

  d = 0;
  res = 0;
  i = strlen(str);
  while ((c = *str++) != '\0') {
    if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) {
      fprintf(stderr, "Invalid hex character: %c\n", c);
      exit(EXIT_FAILURE);
    }

    if ((c >= 'a' && c <= 'f')) {
      d = (c - 'a') + 10;
    } else if ((c >= 'A' && c <= 'F')) {
      d = (c - 'A') + 10;
    } else {
      d = c - '0';
    }

    res = res + (d * pow(16, --i));
  }

  return res;
}
