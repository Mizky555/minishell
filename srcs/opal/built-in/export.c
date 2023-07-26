/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:54:39 by thanapornsi       #+#    #+#             */
/*   Updated: 2023/07/27 00:29:57 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	**sort_env(void)
{
	char	**new_env;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	new_env = str_arr2_dup(environ);
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

void	add_new_env(t_env *env, char *argv)
{
	env->dup_environ = str_arr2_addback(env->dup_environ, argv);
	environ = env->dup_environ;
}

int	check_env(char *environ, char *argv)
{
	int	i;
	int	count;
	int	len_environ;

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
	return (1);
}

void	add_env(t_env *env, char *argv)
{
	int	i;

	i = 0;
	while (environ[i])
	{
		if (check_env(environ[i], argv) == 0)
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

int	ft_export(t_env *env, char **argv)
{
	int	i;

	i = 1;
	if (argv[1] == NULL)
		print_and_free(sort_env());
	else
	{
		while (argv[i])
		{
			add_env(env, argv[i]);
			i++;
		}
	}
	return (0);
}
