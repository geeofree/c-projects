#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int main() {
  char* prompt = getenv("PROMPT");
  if (prompt == NULL) {
    prompt = "$ ";
  }

  printf("Welcome to the shell!\n");
  printf("%s", prompt);

  char* line = get_line();

  while (read_line(&line) != EOF) {
    exec_line(&line);
    printf("%s", prompt);
  }
  printf("\n");

  return EXIT_SUCCESS;
}
