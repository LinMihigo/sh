#include "sh.h"

int main(void)
{
    ssize_t read_chars = get_prompt();

    printf("length of prompt: %ld\n", read_chars);

    return (0);
}
