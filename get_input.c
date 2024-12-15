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
	ssize_t count = 0;
	int c;
	char *temp;

	if (!lineptr || !n || !stream)
		return (-1);

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (!*lineptr)
			return (-1);
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if (count + 1 >= (ssize_t)*n)
		{
			*n *= 2;
			temp = realloc(*lineptr, *n);
			if (!temp)
				return (-1);
			*lineptr = temp;
		}
		(*lineptr)[count++] = c;
		if (c == '\n')
			break;
	}
	if (count == 0)
		return (-1);

	(*lineptr)[count] = '\0';
	return (count);
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
