#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
/* extern variable */
extern char **environ;

/* Functions */
int _strlen(char *s);
char *_strdup(char *str);
char **tokenStore(char *line, const char *dls);


#endif
