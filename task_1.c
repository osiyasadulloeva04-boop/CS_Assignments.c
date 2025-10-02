#include <stdio.h>
#include <cs50.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *name = NULL;
    size_t len = 0;

    printf("What's your name? ");
    if (getline(&name, &len, stdin) == -1)
    {
        free(name);
        return 1;
    }

    /* remove trailing newline if present */
    size_t n = strlen(name);
    if (n > 0 && name[n-1] == '\n')
        name[n-1] = '\0';

    printf("hello, %s\n", name);
    free(name);
    return 0;
}