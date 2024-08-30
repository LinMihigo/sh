#include "shell.h"

/**
 * string_tok - Calls and implements strtok function
 * @str: Command string
 * @delim: Delimiter string
 *
 * Return: Array of command-line arguments
 */

char **string_tok(char *str, char *delim)
{
	char **tokens = malloc(TOKEN_ARRAY_SIZE * sizeof(char *));
	char *token;
	int i, position = 0;

	if (!tokens)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens[position] = _strdup(token);
		if (!tokens[position])
		{
			perror("strdup");
			for (i = 0; i < position; i++)
			{
				_free((void **)&tokens[i]);
			}
			_free((void **)&tokens);
			/* Consider just break; */
			return (NULL);
		}
		position++;
		token = strtok(NULL, delim);
	}
	tokens[position] = NULL;

	return (tokens);
}
