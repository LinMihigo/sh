#include "shell.h"
/**
* find_command - finds the command given the name of it's executable
* @comm: name of the command
* @envp: environment list
* Return: pointer to the path
*/
char *find_command(char *comm, char **envp)
{
	char *dir = NULL;
	int path_size = _path_size(envp);
	char *env_path = get_env_path(envp, path_size);
	char *env_path_copy = strdup(env_path);
	char *comm_path;

	if (!env_path_copy)
		exit(EXIT_FAILURE);

	dir = strtok(env_path_copy, ":");
	while (dir)
	{
		comm_path = malloc(_strlen(comm) + _strlen(dir) + 2);
		if (!comm_path)
		{
			free(env_path_copy);
			exit(EXIT_FAILURE);
		}

		_strcpy(comm_path, dir);
		_strcat(comm_path, "/");
		_strcat(comm_path, comm);

		if (access(comm_path, F_OK) == 0)
		{
			free(env_path_copy);
			return (comm_path);
		}

		free(comm_path);
		dir = strtok(NULL, ":");
	}

	free(env_path_copy);
	return (comm);
}
