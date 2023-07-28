/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:54:27 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/28 21:11:56 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(char *name, t_env *env)
{
	int		i;
	char	*query;

	i = 0;
	query = ft_strjoin(name, "=");
	while (env->environ && env->environ[i])
	{
		if (ft_strncmp(query, env->environ[i], ft_strlen(query)) == 0)
		{
			free(query);
			return (ft_strchr(env->environ[i], '=') + 1);
		}
		i++;
	}
	free(query);
	return (NULL);
}
