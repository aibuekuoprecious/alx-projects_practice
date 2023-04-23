#ifndef SHELL_H
#define SHELL_H

#include <dirent.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"

/* global variable for the environment */
extern char **environ;

/* function prototypes */
char *read_line(void);
char **split_line(char *line, char *delim);
int execute(char **args);
char *find_path(char *prog);
int launch(char *path, char **args);
int is_builtin(char **args);
int run_builtin(char **args);
int cd_builtin(char **args);
int change_directory(char **args);
int update_env_vars(char *oldpwd);
void print_current_dir(void);
int exit_builtin(char **args);
int env_builtin(char **args);
int setenv_builtin(char **args);
int unsetenv_builtin(char **args);
char *get_line(char *buffer, size_t size);

#endif
