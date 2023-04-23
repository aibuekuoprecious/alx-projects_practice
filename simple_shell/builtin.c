#include "shell.h"

/**
 * is_builtin - check if a command is a built-in
 * @args: an array of arguments
 * Return: 1 if true, 0 if false
 */

int is_builtin(char **args)
{
	char *builtins[] = {"cd", "exit", "env", "setenv", "unsetenv", NULL};
	int i, j;
    /* loop through the builtin commands and compare with the first argument */
	for (i = 0; builtins[i] != NULL; i++)
	{
		for (j = 0; args[0][j] != '\0' && builtins[i][j] != '\0'; j++)
			if (args[0][j] != builtins[i][j])
				break;
		if (args[0][j] == '\0' && builtins[i][j] == '\0')
			return (1);
	}
	return (0);
}

/**
 * run_builtin - run a built-in command
 * @args: an array of arguments
 * Return: 0 on success, -1 on error or exit
 */

int run_builtin(char **args)
{
	int i;
	/* check which built-in command to run */
	for (i = 0; args[0][i] != '\0' && "cd"[i] != '\0'; i++)
		if (args[0][i] != "cd"[i])
			break;
	if (args[0][i] == '\0' && "cd"[i] == '\0')
		return (cd_builtin(args));
	for (i = 0; args[0][i] != '\0' && "exit"[i] != '\0'; i++)
		if (args[0][i] != "exit"[i])
			break;
	if (args[0][i] == '\0' && "exit"[i] == '\0')
		return (exit_builtin(args));
	for (i = 0; args[0][i] != '\0' && "env"[i] != '\0'; i++)
		if (args[0][i] != "env"[i])
			break;
	if (args[0][i] == '\0' && "env"[i] == '\0')
		return (env_builtin(args));
	for (i = 0; args[0][i] != '\0' && "setenv"[i] != '\0'; i++)
		if (args[0][i] != "setenv"[i])
			break;
	if (args[0][i] == '\0' && "setenv"[i] == '\0')
		return (setenv_builtin(args));
	for (i = 0; args[0][i] != '\0' && "unsetenv"[i] != '\0'; i++)
		if (args[0][i] != "unsetenv"[i])
			break;
	if (args[0][i] == '\0' && "unsetenv"[i] == '\0')
		return (unsetenv_builtin(args));

	return (0);
}

