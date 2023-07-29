/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:46:48 by thanapornsi       #+#    #+#             */
/*   Updated: 2023/07/29 22:38:05 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"

int	ft_cd(char **argv)
{
	int	value;

	if (argv[0] == NULL)
		value = chdir(getenv("HOME"));
	else
		value = chdir(argv[0]);
	if (value != 0)
	{
		ft_putstr_fd("error", STDERR_FILENO);
		return (1);
	}
	return (0);
}
