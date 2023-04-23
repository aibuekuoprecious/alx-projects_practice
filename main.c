#include "shell.h"

/**
 * main - a simple UNIX command line interpreter
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: EXIT_SUCCESS
 */

int main(int argc, char **argv)
{
	char *line = NULL;
	char **args = NULL;
	int status;
	 /* check arguments */
	if (argc != 1)
	{
		fprintf(stderr, "Usage: %s\n", argv[0]);
		return (EXIT_FAILURE);
	}
	 /* display prompt and wait for user input */
	while (1)
	{
		/* print prompt if interactive mode */
		if (isatty(STDIN_FILENO))
			printf("PCshell$ ");
		 /* read a line from stdin */
		line = read_line();
		if (line == NULL)
			break;
		/* split the line into commands and arguments */
		args = split_line(line, DELIM);
		if (args == NULL)
			continue;
		 /* execute the commands and arguments */
		status = execute(args);
		/* free memory */
		free(line);
		free(args);
		line = NULL;
		args = NULL;
		if (status == -1)
			break;
	}
	/* free memory */
	free(line);
	free(args);

	return (EXIT_SUCCESS);
}
