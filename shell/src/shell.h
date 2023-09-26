#ifndef _SHELL_H
#define _SHELL_H

#include <stddef.h>

char* get_line(void);
int read_line(char** pline);
void exec_line(char** pline);

#endif
