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
	char *delim = DELIM;
	char *comm = NULL;
	char **args = NULL;
	int cmd_count, exec;

	(void)argc;
	(void)argv;
	cmd_count = 0;
	signal(SIGINT, handle_sigint);
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			display_prompt();
		}
		get_input();
		cmd_count++;
		args = string_tok(input, delim);
		if (args[0] == NULL)
			continue;
		comm = args[0];
		exec = exec_builtin(args, envp);
		if (exec != 0)
			continue;
		if (env_function_caller(args) == 0)
			exec_external(comm, args, envp, cmd_count);
		free_resources(args);
		_free((void **)&input);
	}

	return (0);
}
