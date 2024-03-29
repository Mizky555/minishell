/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:47:35 by thanapornsi       #+#    #+#             */
/*   Updated: 2023/07/26 23:51:45 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"

int	argv_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	ft_echo(char **argv)
{
	int	c;
	int	i;
	int	space;

	c = 0;
	i = 1;
	space = 0;
	if (argv_len(argv) >= 2)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'n' && argv[1][2] == '\0')
			c = 1;
		if (c == 1)
			i = 2;
		while (argv[i])
		{
			if (space == 0)
				space = 1;
			else
				printf(" ");
			printf("%s", argv[i++]);
		}
	}
	if (c == 0)
		printf("\n");
	return (0);
}
