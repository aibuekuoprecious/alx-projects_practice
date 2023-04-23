#include "shell.h"

/**
 * env_builtin - print the environment variables
 * @args: an array of arguments
 * Return: 0 on success, -1 on error
 */

int env_builtin(char **args)
{
	int i;
	/* check if no arguments are given */
	if (args[1] == NULL)
	{
		/* loop through the environment variables and print them */
		for (i = 0; environ[i] != NULL; i++)
			printf("%s\n", environ[i]);
		return (0);
	}
	/* otherwise, print an error message */
	fprintf(stderr, "env: too many arguments\n");
	return (-1);
}
