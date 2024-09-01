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
	int i;

	if (args[0] != NULL)
	{
		if (strcmp(args[0], "exit") == 0)
			exit_function(args);
		if (strcmp(args[0], "cd") == 0)
		{
			cd_exec(args, envp);
			return (1);
		}
		if (_strcmp(args[0], "env") == 0)
		{
			get_env();
			return (0);
		}
		else if (_strcmp(args[0], "setenv") == 0)
		{
			set_env(args[1], args[2], 1);
			return (0);
		}
		else if (_strcmp(args[0], "unsetenv") == 0)
		{
			unset_env(args[1]);
			return (0);
		}
	}
	for (i = 0; args[i]; i++)
	{
		_free((void **)&args[i]);
	}
	_free((void **)&args);
	return (0);
}

/**
* exec_external - Executes external commands
* @pathname: Program to execute
* @args: Array of commandline arguments
* @envp: Pointer to array of environment variables
*
* Return: Void
*/
// ! Needs fixing
void exec_external(char *pathname, char *args[], char *envp[])
{
	pid_t pid;
	int status, i;

	is_executable(pathname) && pid = fork();
	if (pid == 0)
	{
		if (execve(pathname, args, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("forking");
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
	}

	for (i = 0; args[i]; i++)
		_free((void **)&args[i]);
	_free((void **)&args);
}
