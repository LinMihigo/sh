#include "shell.h"

/**
 * exec_builtin - Executes built-in commands
 * @args: Array of command-line arguments
 * @envp: Pointer to environment variables
 *
 * Return: Void
 */

int exec_builtin(char *args[], char **envp)
{
	if (args[0] != NULL)
	{
		if (strcmp(args[0], "exit") == 0)
			exit_function(args);
		if (strcmp(args[0], "cd") == 0)
		{
			cd_exec(args, envp);
			return (1);
		}
	}
	return (0);
}

/**
 * exec_external - Executes external commands
 * @comm: Program to execute
 * @args: Array of commandline arguments
 * @envp: Pointer to array of environment variables
 * @cmd_count: Count of commands entered in each shell session
 *
 * Return: Void
 */

void exec_external(char *comm, char *args[], char *envp[], int cmd_count)
{
	pid_t child_pid;
	int status;

	find_ext_file(comm, envp);
	if (comm_path)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Fork Error");
			_free((void **)&comm_path);
			exit_function(args);
		}
		else if (child_pid == 0)
		{
			if ((execve(comm_path, args, envp) == -1))
			{
				perror("execve");
				_free((void **)&comm_path);
				exit_function(args);
			}
		}
		else
		{
			wait(&status);
			_free((void **)&comm_path);
		}
		_free((void **)&comm_path);
	}
	else
	{
		fprintf(stderr, "simple_shell: %d: %s: not found\n", cmd_count, comm);
		_free((void **)&comm_path);
	}
}
