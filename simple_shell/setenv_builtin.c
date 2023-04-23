#include "shell.h"

/**
 * setenv_builtin - set or modify an environment variable
 * @args: an array of arguments
 * Return: 0 on success, -1 on error
 */

int setenv_builtin(char **args)
{
	int status;
	/* check if two arguments are given */
	if (args[1] != NULL && args[2] != NULL)
	{
		/* check if no more arguments are given */
		if (args[3] == NULL)
		{
			/* set or modify the environment variable */
			status = setenv(args[1], args[2], 1);
			if (status == -1)
			{
				perror("setenv");
					return (-1);
			}
			return (0);
		}
	/* otherwise, print an error message */
	fprintf(stderr, "setenv: too many arguments\n");
	return (-1);
	}
	/* otherwise, print an error message */
	fprintf(stderr, "setenv: too few arguments\n");
	return (-1);
}
