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
	char *input = NULL;
	char *delim = DELIM;
	char *str = NULL;
	char *comm = NULL;
	char **args = NULL;
	int cmd_count, exec;

	(void)argc;
	(void)argv;
	cmd_count = 0;
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			display_prompt();
		}
		str = get_input(input, sizeof(input));
		cmd_count++;
		args = string_tok(str, delim);
		if (args[0] == NULL)
		{
			continue;
		}
		comm = args[0];
		exec = exec_builtin(args, envp);
		if (exec != 0)
			continue;
		if (env_function_caller(args) == 0)
			exec_external(comm, args, envp, cmd_count);
		free_resources(args);
		_free((void **)&str);
		_free((void **)&input);
	}
	free_resources(args);
	_free((void **)&str);
	_free((void **)&input);

	return (0);
}
