#include "shell.h"

/**
 * execute - execute a program with arguments
 * @args: an array of arguments
 * Return: 0 on success, -1 on error or exit
 */

int execute(char **args)
{
	char *path;
	int i;
	/* check if the arguments are empty */
	if (args[0] == NULL)
		return (0);
	/* check if the command is a built-in */
	if (is_builtin(args))
		return (run_builtin(args));
	/* check if the command is an absolute path or a built-in command */
	if (args[0][0] == '/')
		path = args[0];
	else
	{
		for (i = 0; args[0][i] != '\0' && "cd"[i] != '\0'; i++)
			if (args[0][i] != "cd"[i])
				break;
		if (args[0][i] == '\0' && "cd"[i] == '\0')
			path = args[0];
		else
		{
			for (i = 0; args[0][i] != '\0' && "env"[i] != '\0'; i++)
				if (args[0][i] != "env"[i])
					break;
			if (args[0][i] == '\0' && "env"[i] == '\0')
				path = args[0];
			else
				path = find_path(args[0]);
		}
	}
	/* launch the program with arguments */
	return (launch(path, args));
}

