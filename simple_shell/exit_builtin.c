#include "shell.h"

/**
 * exit_builtin - exit the shell
 * @args: an array of arguments
 * Return: -1 to indicate exit
 */

int exit_builtin(char **args)
{
	int status = 0;
	int i;
	/* check if an argument is given */
	if (args[1] != NULL)
	{
		/* convert the argument to an integer and use it as the exit status */
		for (i = 0; args[1][i] != '\0'; i++)
		{
			if (args[1][i] >= '0' && args[1][i] <= '9')
				status = status * 10 + args[1][i] - '0';
			else
				break;
		}
		exit(status);
	}
	/* otherwise, use 0 as the exit status */
	exit(0);
	return (-1);
}

