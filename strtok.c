#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
   int j;
   char *str, *token;
   
   for (j = 1; j < argc; j++)
   {
       str = argv[j];
       printf("j: %d, str: %s\n", j, str);
       token = strtok(str, " ");
       while (token != NULL)
       {
           printf("arg[%d]: %s\n", j, token);
           token = strtok(NULL, " ");
       }
        printf("\n");
   }
   
   return (0);
}#include <string.
