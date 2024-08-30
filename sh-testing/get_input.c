#include "shell.h"

/**
* get_input - Gets input from the commandline
* @lineptr: The pointer to the command string
* @len: Size of string
*
* Return: Void
*/
char *get_input(char *lineptr, size_t len)
{
	ssize_t nread;

	nread = getline(&lineptr, &len, stdin);
	if (nread == -1)
	{
		perror("getline");
		free(lineptr);
		return (NULL);
	}

	return (lineptr);
}
