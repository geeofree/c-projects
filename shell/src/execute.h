#ifndef _EXECUTE_H
#define _EXECUTE_H

#define DEFAULT_ARG_STR_LEN 4

/** Array of arguments. */
typedef char** Arguments;

/** Parse and execute the line buffer. */
void execute(char *line);
#endif
