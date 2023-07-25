#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"

int	env_vs_argv(char *argv, char *env)
{
	int	i;

	i = 0;
	while (argv[i] == env[i])
		i++;
	if (argv[i] == '\0' && env[i] == '=')
		return (1);
	return (0);
}

int    unset_env(t_env *env, char *argv)
{
    int i;

    i = 0;
    if (ft_strchr(argv, '='))
    {
        ft_putstr_fd("unset: ", 2);
		ft_putstr_fd(argv, 2);
		ft_putstr_fd(": invalid parameter name\n", 2);
        return (1);
    }
    while (environ[i])
    {
        if (env_vs_argv(argv, environ[i]))
		{
			str_arr2_delfront(&env->dup_environ[i]);
			environ = env->dup_environ;
			return (0);
		}
        i++;
    }
    return (0);
}

int ft_unset(t_env *env, char **argv)
{
    int i;

    i = 0;
    while (argv[i])
    {
        env->ret = unset_env(env, argv[i]);
        i++;
    }
    return (EXIT_SUCCESS);
}