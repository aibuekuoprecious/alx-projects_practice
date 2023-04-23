#include "shell.h"

/**
 * get_path_value - get the value of PATH environment variable
 *
 * Return: the value of PATH, or NULL if not found
 */

char *get_path_value(void)
{
	int i;
	char *path = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = strdup(environ[i] + 5);
			break;
		}
	}
	return (path);
}

/**
 * create_full_path - create the full path of a program
 * @dir: a directory in PATH
 * @prog: the name of the program
 *
 * Return: the full path of the program, or NULL if not found
 */

char *create_full_path(char *dir, char *prog)
{
	char *full_path = NULL;
	int i, j;

	i = strlen(dir);
	j = strlen(prog);
	full_path = malloc(sizeof(char) * (i + j + 2));
	if (full_path == NULL)
		return (NULL);
	for (i = 0; dir[i] != '\0'; i++)
		full_path[i] = dir[i];
	full_path[i++] = '/';
	for (j = 0; prog[j] != '\0'; j++)
		full_path[i + j] = prog[j];
	full_path[i + j] = '\0';
	return (full_path);
}

/**
 * find_executable - find an executable file in a directory
 * @dir: a directory in PATH
 * @prog: the name of the program
 *
 * Return: 1 if the file exists and is executable, 0 otherwise
 */

int find_executable(char *dir, char *prog)
{
	char *full_path = create_full_path(dir, prog);
	int result = access(full_path, X_OK);

	free(full_path);
	return (result == 0);
}

/**
 * find_path - find the full path of a program
 * @prog: the name of the program
 *
 * Return: the full path of the program, or NULL if not found
 */
char *find_path(char *prog)
{
	char *path = get_path_value();
	char *token = NULL;
	char *full_path = NULL;

	if (path == NULL)
		return (NULL);
	token = strtok(path, ":");
	while (token != NULL)
	{
		if (find_executable(token, prog))
		{
			full_path = create_full_path(token, prog);
			break;
		}
		token = strtok(NULL, ":");
	}
	free(path);
	return (full_path);
}

