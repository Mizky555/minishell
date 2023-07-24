#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_env(void)
{
    int i;

    i = 0;
    while (environ[i])
    {
        if (ft_strncmp(environ[i], "_=", 2) != 0)
            printf("%s\n", environ[i]);
        i++;
    }
    printf("_=%s\n", getenv("_"));
    return (EXIT_SUCCESS);
}