#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"

extern char **environ;

int _execute(char **command, char **argv, int idx);
void freecmd(char **arr);

char *read_line(void);
char **tokenizer(char *line);

char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

char *_getenv(char *var);
char *_getpath(char *command);

char *_itoa(int n);
void reverse_string(char *str, int len);
void print_error(char *name, char *cmd, int idx);

void handle_builtin(char **command, char **argv, int *status, int idx);
int is_builtin(char *command);
void exit_shell(char **command, char **argv, int *status, int idx);
void print_env(char **command, int *status);

int is_positive_number(char *str);
int _atoi(char *str);

#endif
