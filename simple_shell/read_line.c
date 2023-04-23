#include "shell.h"

/**
 * read_line - read a line from stdin
 * Return: a pointer to the line, or NULL on error or EOF
 */

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	/* use getline function to read a line from stdin */
	read = getline(&line, &len, stdin);
	/* handle end of file */
	if (read == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			return (NULL);
		}
		/* handle error */
		else
		{
			perror("getline");
			return (NULL);
		}
	}
	return (line);
}
