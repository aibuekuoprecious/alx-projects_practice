#include "shell.h"

/**
 * split_line - split a line into tokens
 * @line: the line to split
 * @delim: the delimiter to use
 * Return: an array of tokens, or NULL on failure
 */

char **split_line(char *line, char *delim)
{
	char **tokens = NULL;
	char *token = NULL;
	int bufsize = BUFSIZE;
	int i = 0;
	/* allocate memory for tokens */
	tokens = malloc(sizeof(char *) * bufsize);
	if (tokens == NULL)
		return (NULL);
	/* get the first token */
	token = strtok(line, delim);
	/* loop through the line and get the rest of the tokens */
	while (token != NULL)
	{
		/* store the token in the array */
		tokens[i] = token;
		i++;
		/* reallocate memory if necessary */
		if (i >= bufsize)
		{
			bufsize += BUFSIZE;
			tokens = realloc(tokens, sizeof(char *) * bufsize);
			if (tokens == NULL)
				return (NULL);
		}
		/* get the next token */
		token = strtok(NULL, delim);
	}
	/* null-terminate the array */
	tokens[i] = NULL;
	return (tokens);
}
