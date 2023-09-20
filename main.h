#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* extern variable */
extern char **environ;

/* Functions */
int _strlen(char *s);
char *_strdup(char *str);
char *_strchr(char *str, char c);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str, const char *s);
char *find_command(char *command);
char **tokenStore(char *line, const char *dls);


#endif
