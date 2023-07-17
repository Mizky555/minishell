//1 function
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int pwds(void)
{
    char *pwd;

    pwd = getcwd(NULL, 0);
    printf("%s\n",pwd);
    free(pwd);
    return (EXIT_SUCCESS);
}

