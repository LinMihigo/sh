#include "sh.h"

ssize_t get_prompt()
{
    char *promptptr = NULL;
    size_t promptlen;
    ssize_t chars_read;

    while (1)
    {
        //TODO: Feature - Add current file path
        printf("$ ");
        chars_read = getline(&promptptr, &promptlen, stdin);
        if (chars_read == -1)
        {
            perror("getline");
            exit(EXIT_FAILURE);
        }
        else
        {
            _parser(promptptr);
        }
        free(promptptr);
        promptr = NULL;
    }
    return (chars_read);
}
