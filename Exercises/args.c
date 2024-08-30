#include <stdio.h>
/**
* main - prints args without using ac
* Return: 0
*/
int main(int ac __attribute__((unused)), char **av)
{
	int i = 0;

	while (av[i] != NULL)
	{
		printf("Arg[%d]: %s\n", i, av[i]);
		i++;
	}

	return (0);
}
