#include "shell.h"

/**
 * launch - launch a program with arguments
 * @path: the full path of the program
 * @args: an array of arguments
 * Return: 0 on success, -1 on error or exit
 */

int launch(char *path, char **args)
{
	pid_t pid;
	int status;
	/* fork a child process */
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	/* child process executes the program */
	if (pid == 0)
	{
		/* check if the program exists and is executable */
		if (path != NULL && access(path, X_OK) == 0)
		{
			/* execute the program with arguments and environment variables */
			if (execve(path, args, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			fprintf(stderr, "%s: command not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	/* parent process waits for the child process */
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while
		(!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}
