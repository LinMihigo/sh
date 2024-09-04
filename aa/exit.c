#include "shell.h"

/**
 * exit_function - Executes exit built-in
 * @args: Array of command-line arguments
 *
 * Return: Void
 */

void exit_function(char *args[])
{
	int status;

	if (args[1] != NULL)
		status = atoi(args[1]);
	else
		status = 0;
	free_resources(args);
	free_resources(environ_copy);
	exit(status);
}
