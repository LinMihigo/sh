#include "shell.h"

/**
 * shell_path_exec - Executes path outside of environment
 * @pathname: Path
 *
 * Return: Pointer to path
 */

char *shell_path_exec(char *pathname)
{
	if (strchr(pathname, '/') != NULL)
	{
		if (is_executable(pathname))
		{
			return (pathname);
		}
	}

	return ('\0');
}
