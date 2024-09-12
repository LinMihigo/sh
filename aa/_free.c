#include "shell.h"

/**
 * _free - custom free function for double pointers
 * @ptr: pointer to the double pointer to clear
 * Return: void
 */
void _free(void **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

/**
 * free_resources - function to use _free to free double pointers
 * @args: double pointer to free
 * Return: void
 */
void free_resources(char **args)
{
	int i;

	if (args)
	{
		for (i = 0; args[i] != NULL; i++)
			_free((void **)&args[i]);
		_free((void **)&args);
	}
}
