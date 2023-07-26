/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:46:48 by thanapornsi       #+#    #+#             */
/*   Updated: 2023/07/26 23:47:10 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"

int	ft_cd(char **argv)
{
	int	value;

	if (argv[1] == NULL)
		value = chdir(getenv("HOME"));
	else
		value = chdir(argv[1]);
	if (value != 0)
	{
		ft_putstr_fd("error", STDERR_FILENO);
		return (1);
	}
	return (0);
}
