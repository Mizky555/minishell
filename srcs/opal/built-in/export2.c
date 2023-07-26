/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:25:35 by thanapornsi       #+#    #+#             */
/*   Updated: 2023/07/27 00:26:21 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	index_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

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

int	len_arr2(char **str)
{
	int	len;

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
