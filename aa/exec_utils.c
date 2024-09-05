#include "shell.h"

/**
 * _path_size - Get envp path size
 * @envp: Environment variable
 *
 * Return: Size of path
 */
int _path_size(char **envp)
{
	int i = 0, j = 5;

	while (envp[i] != NULL)
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A' &&
			envp[i][2] == 'T' && envp[i][3] == 'H')
		{
			while (envp[i][j++] != '\0')
				;
		}
		i++;
	}

	return (j);
}

/**
 * get_env_path - Get the env path
 * @envp: Environment variable
 * @size: Size of environment path variable
 *
 * Return: Pointer to path variable
 */

char *get_env_path(char **envp, int size)
{
	char *path;
	int i = 0, j = 5, k = 0;

	path = malloc(sizeof(char) * (size + 1));
	path[size] = '\0';
	while (envp[i] != NULL)
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A' && envp[i][2] == 'T' && envp[i][3] == 'H')
		{
			while (envp[i][j++] != '\0')
				path[k++] = envp[i][j];
		}
		i++;
	}

	return (path);
}

/**
 * _concatenate - Concatenate strings
 * @dir: Executable directory
 * @pathname: Command name
 *
 * Return: Full path to command path
 */

char *_concatenate(char *dir, char *comm)
{
	size_t i, j, k, dir_len = _strlen(dir), comm_len = _strlen(comm);

	if (comm_path)
		_free((void **)&comm_path);
	comm_path = malloc(sizeof(char) * (dir_len + comm_len + 2));
	if (!comm_path)
	{
		perror("Fullpath error");
		exit(EXIT_FAILURE);
	}
	comm_path[dir_len + comm_len + 1] = '\0';
	for (i = 0; dir[i] != '\0'; i++)
	{
		comm_path[i] = dir[i];
	}
	comm_path[i] = '/';
	for (j = i + 1, k = 0; comm[k] != 0; j++, k++)
	{
		comm_path[j] = comm[k];
	}

	return (comm_path);
}

/**
 * find_ext_file - Find external command file
 * @pathname: The command to search for
 * @envp: Environment variable
 * @cmd_count: Count of commands entered in each shell session
 *
 * Return: Path to command
 */
char *find_ext_file(char *comm, char **envp)
{
	char *dir;
	char *env_path = NULL;

	env_path = get_env_var_value(envp, "PATH");
	dir = strtok(env_path, ":");
	while (dir != NULL)
	{
		if (comm[0] == '/' || comm[0] == '.')
			comm_path = comm;
		else
			comm_path = _concatenate(dir, comm);
		if (access(comm_path, F_OK) == 0)
		{
			_free((void **)&env_path);
			return (comm_path);
		}
		dir = strtok(NULL, ":");
	}
	_free((void **)&env_path);
	_free((void **)&comm_path);
	return (NULL);
}
