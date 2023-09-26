#include <sys/wait.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "shell.h"
#include "mem.h"

char** _get_args(char* line, size_t* len);
void _execute(char** args, size_t args_len);
void _clean_args(char** args, size_t args_len);

char* get_line() {
  return (char*)memalloc(sizeof(char));
}

int read_line(char **pline) {
  size_t i = 0;

  while (((*pline)[i] = getchar()) != EOF) {
    if ((*pline)[i] == '\n') {
      (*pline)[i] = '\0';
      return EXIT_SUCCESS;
    } else {
      i++;
      *pline = (char*)memrealloc(*pline, sizeof(char) * (i + 1));
    }
  }

  free(*pline);
  return EOF;
}

void exec_line(char** pline) {
  size_t args_len;
  char** args = _get_args(*pline, &args_len);

  if (strcmp(args[0], "exit") == 0) {
    _clean_args(args, args_len);
    free(*pline);
    printf("Bye bye!\n");
    exit(EXIT_SUCCESS);
  }

  _execute(args, args_len);
  *pline = (char*)memrealloc(*pline, sizeof(char));
}

char** _get_args(char* line, size_t* len) {
  char** args = (char**)memalloc(sizeof(char*));
  *args = (char*)memalloc(sizeof(char));

  size_t args_len = 0, arg_str_len = 0, line_index = 0;

  while ((args[args_len][arg_str_len] = line[line_index++])) {
    if (args[args_len][arg_str_len] == ' ') {
      args[args_len++][arg_str_len] = '\0';
      args = (char**)memrealloc(args, sizeof(char*) * (args_len + 1));
      args[args_len] = (char*)memalloc(sizeof(char));
      arg_str_len = 0;
    } else {
      arg_str_len++;
      args[args_len] = (char*)memrealloc(args[args_len], sizeof(char) * (arg_str_len + 1));
    }
  }
  args[args_len++][arg_str_len] = '\0';
  args = (char**)memrealloc(args, sizeof(char*) * (args_len + 1));

  *len = args_len;

  return args;
}

void _execute(char** args, size_t args_len) {
  pid_t pid = fork();

  if (pid == -1) {
    fprintf(stderr, "Could not create child process: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  if (pid == 0) {
    int command = execvp(args[0], args);

    if (command == -1) {
      fprintf(stderr, "Could not execute command `%s`: %s\n", args[0], strerror(errno));
      exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
  }

  waitpid(pid, NULL, 0);
  _clean_args(args, args_len);
}

void _clean_args(char** args, size_t args_len) {
  size_t i;
  for (i = 0; i < args_len; i++) free(args[i]);
  free(args);
}
