#include "shell.h"

/**
 * get_input - Gets input from the commandline
 *
 * Return: Void
 */

void get_input(void)
{
	ssize_t char_read;
	size_t len;

	input = NULL;
	len = sizeof(input);
	char_read = getline(&input, &len, stdin);
	if (char_read == -1)
	{
		if (feof(stdin))
		{
			_free((void **)&input);
			/*	write(STDOUT_FILENO, "\n", 1);	*/
			exit(EXIT_SUCCESS);
		}
		else
		{
			_free((void **)&input);
			perror("Getline Error");
			exit(EXIT_FAILURE);
		}
	}

	/*if (char_read > 0 && lineptr[char_read - 1] == '\n')*/
	/*{*/
	/*	lineptr[char_read - 1] = '\0';*/
	/*}*/
}
