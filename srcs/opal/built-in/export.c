#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while ((*(s1 + i) || *(s2 + i)))
	{
		if (*(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *((s2 + i)));
		i++;
	}
	return (0);
}

int len_arr2(char **str)
{
    int len;

    len = 0;
    while (str[len])
    {
        len++;
    }
    return (len);
}

void	print_and_free(char **new_env)
{
	int	i;

	i = 0;
	while (new_env[i])
	{
		printf("%s\n", new_env[i]);
		free(new_env[i]);
        i++;
	}
	free(new_env);
}

char    **sort_env(void)
{
    char    **new_env;
    char    *tmp;
    int i;
    int j;

    i = 0;
    new_env = str_arr2_dup(environ); //cpy ทั้งก้อนมาวนเรียงใหม่
	while (i < len_arr2(environ))
	{
		j = i + 1;
		while (j < len_arr2(environ))
		{
			if (ft_strcmp(new_env[i], new_env[j]) > 0)
			{
				tmp = new_env[i];
				new_env[i] = new_env[j];
				new_env[j] = tmp;
			}
			j++;
		}
		i++;
	}
    return (new_env);
}

int index_equal(char *str)
{
    int i;

    i = 0;
    while (str[i] != '=' && str[i] != '\0')
    {
        i++;
    }
    return (i);
}

void    add_new_env(t_env *env, char *argv)
{
    env->dup_environ = str_arr2_addback(env->dup_environ, argv);
    environ = env->dup_environ;
}

int check_env(char *environ, char *argv)
{
    int i;
    int count;
    int len_environ;

    i = 0;
    count = 0;
    len_environ = index_equal(environ);
    while (environ[i] && argv[i] && argv[i] != '=')
    {
        if (argv[i] == environ[i])
            count++;
        if (count == len_environ)
            return (0);
        i++;
    }
    return(1);
}

void    add_env(t_env *env, char *argv)
{
    int i;

    i = 0;
    while (environ[i])
    {
        if (check_env(environ[i],argv) == 0)
        {
            free(environ[i]);
            environ[i] = ft_strdup(argv);
            return ;
        }
        i++;
    }
    if (ft_strchr(argv, '='))
        add_new_env(env, argv);
}

int ft_export(t_env *env, char **argv)
{
    int i;

    i = 1;
    if (argv[1] == NULL)
        print_and_free(sort_env());
    else
        while (argv[i])//ถัดไปทีละstr 
        {
            add_env(env, argv[i]);
            i++;
        }
        return (0);
}
// int check_env(t_env *env, char *argv)
// {
//     int i;
//     int j;
//     int count;

//     j = 0;
//     i = 0;
//     while (environ[i])
//     {
//         count = 0;
//         j = 0;
//         while (environ[i][j] && argv[j] && argv[j] != '=')
//         {
//             j++;
//             if (argv[j] == environ[i][j])
//                 count++;
//         }
//         if (count == index_equal(environ[i]))
//         {
//             free(environ[i]);
//             return (1);
//         }
//         i++;
//     }
//     return(0);
// }