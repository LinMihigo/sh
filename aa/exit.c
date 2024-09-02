#include "shell.h"

/**
 * exit_function - Executes exit built-in
 * @args: Array of command-line arguments
 *
 * Return: Void
 */

void exit_function(char *args[])
{
	int status, i;

	if (args[1] != NULL)
		status = atoi(args[1]);
	else
		status = 0;
	for (i = 0; args[i] != NULL; i++)
		_free((void **)&args[i]);
	_free((void **)&args);
	exit(status);
}
