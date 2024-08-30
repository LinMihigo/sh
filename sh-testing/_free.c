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
