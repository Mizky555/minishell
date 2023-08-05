/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:54:16 by thanapornsi       #+#    #+#             */
/*   Updated: 2023/08/05 13:21:08 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_exit_numric(char **argv)
{
	ft_putstr_fd("miniopal: exit: ", STDERR_FILENO);
	ft_putstr_fd(argv[1], STDERR_FILENO);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
	return (2);
}

int	ft_exit(t_env *env, char **argv)
{
	int	i;
	int	ret;

	env->exit = 0;
	ret = 0;
	if (len_arr2(argv) > 1)
	{
		i = -1;
		while (argv[1][++i])
			if (!ft_isdigit(argv[1][i]))
				return (ft_exit_numric(argv));
		ret = (ft_atoi(argv[1]));
	}
	if (len_arr2(argv) > 2)
	{
		i = -1;
		while (argv[1][++i])
			if (!ft_isdigit(argv[1][i]))
				return (ft_exit_numric(argv));
		ft_putstr_fd("miniopal: exit: too many arguments\n", STDERR_FILENO);
		env->exit = 1;
	}
	return (ret);
}
