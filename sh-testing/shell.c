#include "shell.h"

/**
 * main - Shell program entry point
 * @argc: Number of commandline arguments
 * @argv: Pointer to array of commandline arguments
 * @envp: Pointer to array of environment variables
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[], char *envp[])
{
	char input[128];
	char *delim = DELIM;
	char *str = NULL;
	char *pathname = NULL;
	char **args = NULL;
	int i;

	(void)argc;
	(void)argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();

		str = get_input(input, sizeof(input));
		if (str == NULL)
			continue;

		args = string_tok(str, delim);
		if (args == NULL || args[0] == NULL)
		{
			_free((void **)&str);
			_free((void **)&args);
			continue;
		}

<<<<<<< HEAD
		pathname = (strchr(pathname, '/') ? args[0] : find_command(args[0], envp));
		if (args[0] == NULL)
		{
			for (i = 0; args[i] != NULL; i++)
				_free((void **)&args[i]);
			_free((void **)&args);
			_free((void **)&str);
			continue;
		}
=======
		pathname = args[0];
>>>>>>> 55ca014061082b86ad29b988874c530cdd61e331
		if (exec_builtin(args, envp) == 1)
			continue;
		exec_external(pathname, args, envp);
		
		for (i = 0; args[i] != NULL; i++)
			_free((void **)&args[i]);
		_free((void **)&args);
		_free((void **)&str);
	}

	for (i = 0; args[i] != NULL; i++)
		_free((void **)&args[i]);
	_free((void **)&args);
	_free((void **)&str);

	return (0);
}
