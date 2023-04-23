#include "shell.h"

/**
 * get_line - read a line from a file descriptor
 * @buffer: a pointer to a buffer to store the line
 * @size: the size of the buffer
 * Return: the number of bytes read, or -1 on error or EOF
 */

char *get_line(char *buffer, size_t size)
{
	static char buf[BUFSIZE];
	static char *ptr;
	static int n;
	int i;
	/* check if the buffer is valid */
	if (buffer == NULL || size <= 0)
		return (NULL);
	/* loop until a newline or EOF is found */
	for (i = 0; i < size - 1; i++)
	{
		/* check if the static buffer is empty */
		if (n == 0)
		{
			/* read from stdin and store in the static buffer */
			n = read(STDIN_FILENO, buf, BUFSIZE);
			if (n == -1)
				return (NULL);
			if (n == 0)
				return (NULL);
			ptr = buf;
		}
		/* copy a character from the static buffer to the given buffer */
		buffer[i] = *ptr;
		ptr++;
		n--;
		/* check if a newline is found */
		if (buffer[i] == '\n')
			break;
	}
	/* null-terminate the given buffer */
	buffer[i] = '\0';
	return (buffer);
}
