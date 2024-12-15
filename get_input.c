#include "shell.h"

/**
* _getline - custom getline function
* @lineptr: pointer addr. to buffer containing line read from stream
* @n: size of buffer
* @stream: input source
* Return: number of chars read
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int fd = fileno(stream);
	void *buf = malloc(1024);

	read(fd, buf, sizeof(buf));
	*lineptr = _strdup(buf);

	*n = sizeof(*lineptr);
	free(buf);

	return ((ssize_t)n);
}

/**
 * get_input - Gets input from the commandline
 *
 * Return: Void
 */

void get_input(void)
{
	ssize_t char_read;
	size_t len = 0;

	glob.input = NULL;
	len = sizeof(glob.input);
	char_read = getline(&glob.input, &len, stdin);
	if (char_read == -1)
	{
		if (feof(stdin))
		{
			_free((void **)&glob.input);
			/*	write(STDOUT_FILENO, "\n", 1);	*/
			exit(EXIT_SUCCESS);
		}
		else
		{
			_free((void **)&glob.input);
			perror("Getline Error");
			exit(EXIT_FAILURE);
		}
	}

	/*if (char_read > 0 && lineptr[char_read - 1] == '\n')*/
	/*{*/
	/*	lineptr[char_read - 1] = '\0';*/
	/*}*/
}
