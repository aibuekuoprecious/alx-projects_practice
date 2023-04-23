#include "shell.h"

/**
 * cd_builtin - change the current directory
 * @args: an array of arguments
 * Return: 0 on success, -1 on error
 */

int cd_builtin(char **args)
{
	char *oldpwd, *newpwd;
	int status;

	oldpwd = getcwd(NULL, 0);
	if (oldpwd == NULL)
	{
		perror("getcwd");
		return (-1);
	}
	status = change_directory(args);
	if (status == -1)
	{
		free(oldpwd);
		return (-1);
	}
	status = update_env_vars(oldpwd);
	free(oldpwd);
	return (status);
}

/**
 * change_directory - change to the given directory
 * @args: an array of arguments
 * Return: 0 on success, -1 on error
 */

int change_directory(char **args)
{
	int status;

	if (args[1] == NULL || strcmp(args[1], "~") == 0)
	{
		status = chdir(getenv("HOME"));
		if (status == -1)
		{
			perror("chdir");
			return (-1);
		}
	}
	else if (strcmp(args[1], "-") == 0)
	{
		status = chdir(getenv("OLDPWD"));
		if (status == -1)
		{
			perror("chdir");
			return (-1);
		}
		print_current_dir();
	}
	else
	{
		status = chdir(args[1]);
		if (status == -1)
		{
			perror("chdir");
			return (-1);
		}
	}
	return (0);
}

/**
 * update_env_vars - update environment variables PWD and OLDPWD
 * @oldpwd: old working directory
 * Return: 0 on success, -1 on error
 */

int update_env_vars(char *oldpwd)
{
	char *newpwd;
	int status;

	newpwd = getcwd(NULL, 0);
	if (newpwd == NULL)
	{
		perror("getcwd");
		return (-1);
	}
	status = setenv("OLDPWD", oldpwd, 1);
	if (status == -1)
	{
		perror("setenv");
		free(newpwd);
		return (-1);
	}
	status = setenv("PWD", newpwd, 1);
	if (status == -1)
	{
		perror("setenv");
		free(newpwd);
		return (-1);
	}
	free(newpwd);
	return (0);
}

/**
 * print_current_dir - print the current working directory
 */

void print_current_dir(void)
{
	char *cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		perror("getcwd");
		return;
	}
	printf("%s\n", cwd);
	free(cwd);
}

