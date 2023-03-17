#include "execute.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

static unsigned int arg_str_len = DEFAULT_ARG_STR_LEN;
static unsigned int args_len = 1;

void execute(char *line) {
  Arguments args = malloc(sizeof(char *));
  *args = malloc(sizeof(char) * arg_str_len);

  char **start_args = args;
  char *start_arg_str = *args;

  char c;
  unsigned int i = 0;
  while ((c = *line++)) {
    if (c == ' ' && i > 0) {
      **args = '\0';
      *args -= *args - start_arg_str;
      args_len = args - start_args;
      args -= args_len;
      args_len += 1;
      args = realloc(args, sizeof(char *) * args_len + 1);
      start_args = args;
      args += args_len;
      arg_str_len = DEFAULT_ARG_STR_LEN;
      *args = malloc(sizeof(char) * arg_str_len);
      start_arg_str = *args;
      i = *args - start_arg_str;
      continue;
    }

    **args = c;
    ++*args;
    i = *args - start_arg_str;

    if (i > arg_str_len) {
      *args -= i;
      arg_str_len += DEFAULT_ARG_STR_LEN;
      *args = realloc(*args, sizeof(char) * arg_str_len);
      *args += i;
    }
  }

  if (c == '\0') {
    **args = '\0';
    *args -= *args - start_arg_str;
    args_len = args - start_args;
    args -= args_len;
    args_len += 1;
    args = realloc(args, sizeof(char *) * (++args_len));
  }

  pid_t pid = fork();

  if (pid == -1) {
    fprintf(stderr, "Could not create child process: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  if (pid == 0) {
    int command = execvp(*args, args);

    if (command == -1) {
      fprintf(stderr, "Command failed to execute: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
  }

  waitpid(pid, NULL, 0);

  while (args_len > 0) free(args[--args_len]);
  free(args);
}
