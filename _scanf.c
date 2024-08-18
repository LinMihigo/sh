#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t chars_read;

    while (1)
    {
        printf("$ ");
        chars_read = getline(&lineptr, &n, stdin);
        if (chars_read == -1)
        {
            printf("\ngetline failed or reached end of line\n");
            return(1);
        }
        else
        {
            printf("%s\n", lineptr);
        }
        free(lineptr);
        lineptr = NULL;
    }
    return (0);
}
