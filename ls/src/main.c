#include <asm-generic/errno-base.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

#define BUF_SIZE 1024

/** Print error and exit with failure status. */
void eprint(int, ...);

int main(int argc, char **argv) {
  char *path;

  if (argc > 1) {
    path = argv[argc - 1];
  } else {
    char buf[BUF_SIZE];
    path = getcwd(buf, BUF_SIZE);

    if (path == NULL) eprint(0);
  }

  DIR *dir = opendir(path);

  if (dir == NULL) eprint(1, path);

  struct dirent *ent;

  while ((ent = readdir(dir)) != NULL) {
    if (ent->d_name[0] == '.') continue;
    printf("%s/%s\n", path, ent->d_name);
  }

  closedir(dir);

  return 0;
}

void eprint(int count, ...) {
  if (count > 1 || count < 0) {
    fprintf(stderr, "Invalid use of eprint: count should be either 1 or 0 received %d\n", count);
    return;
  }

  va_list args;

  va_start(args, count);
  char *message;
  if (count == 1) {
    message = va_arg(args, char *);
  }
  va_end(args);

  switch (errno) {
    case EACCES:
    case ENOTDIR:
    case ENOENT:
      fprintf(stderr, "%s: %s\n", strerror(errno), message);
      break;

    default:
      fprintf(stderr, "%s\n", strerror(errno));
      break;
  }

  exit(EXIT_FAILURE);
}
