#ifndef SHELL
#define SHELL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdarg.h>
extern char **environ;
int gt(char **);
int Pfind(char **);
int _strlen(char *);
int _strcmp(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(char *);
char *_getenv(const char *);
int die_free(char *, ...);
int tokcont(char *, char *);
#endif
