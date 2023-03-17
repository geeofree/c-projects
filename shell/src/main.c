#include <stdio.h>
#include <stdlib.h>
#include "readline.h"
#include "execute.h"

#define MAX_LINE_BUFFER_LENGTH 128

int main() {
  printf("Welcome to the shell!\n");

  char line_buf[MAX_LINE_BUFFER_LENGTH];
  int line_length;

  char *prompt = getenv("PROMPT");

  if (prompt == NULL) {
    prompt = "$ ";
  }

  printf("%s", prompt);
  while ((line_length = readline(line_buf, MAX_LINE_BUFFER_LENGTH)) != EOF) {
    if (line_length >= MAX_LINE_BUFFER_LENGTH) {
      fprintf(stderr, "ERROR: Input length exceeded max line buffer length.\n");
      return EXIT_FAILURE;
    }

    execute(line_buf);
    printf("%s", prompt);
  }

  if (line_length == EOF) printf("\n");

  return EXIT_SUCCESS;
}
