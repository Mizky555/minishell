/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:52:38 by thanapornsi       #+#    #+#             */
/*   Updated: 2023/07/28 20:47:40 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_env(char **environ)
{
	int	i;

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
