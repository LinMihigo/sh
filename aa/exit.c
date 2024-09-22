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
	if (args != NULL)
		free_resources(args);
	if (environ_copy)
		free_resources(environ_copy);
	if (input)
		_free((void **)&input);
	exit(status);
}

/**
 * handle_sigint - handle exit at Ctrl + C
 * @sig: Int representing the signal that was caught by the OS
 * Return: void
 */
void handle_sigint(int sig)
{
	free_resources(environ_copy);
	_free((void **)&input);
	exit(sig);
}
