#include "shell.h"

/**
 * unsetenv_builtin - remove an environment variable
 * @args: an array of arguments
 * Return: 0 on success, -1 on error
 */

int unsetenv_builtin(char **args)
{
	int status;
	/* check if one argument is given */
	if (args[1] != NULL)
	{
		/* check if no more arguments are given */
		if (args[2] == NULL)
		{
			/* remove the environment variable */
			status = unsetenv(args[1]);
			if (status == -1)
			{
				perror("unsetenv");
				return (-1);
			}
			return (0);
		}
		/* otherwise, print an error message */
		fprintf(stderr, "unsetenv: too many arguments\n");
		return (-1);
	}
	/* otherwise, print an error message */
	fprintf(stderr, "unsetenv: too few arguments\n");
	return (-1);
}
