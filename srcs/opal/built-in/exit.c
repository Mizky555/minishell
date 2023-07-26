/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:54:16 by thanapornsi       #+#    #+#             */
/*   Updated: 2023/07/26 23:54:17 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(t_env *env, char **argv)
{
	env->exit = 0;
	if (len_arr2(argv) > 1)
		return (ft_atoi(argv[1]));
	else
		return (0);
}
