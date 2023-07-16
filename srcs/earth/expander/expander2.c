/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:25:36 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/16 19:25:42 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_error(t_env *env, char *token, char *pos, char **next_pos)
{
	char	*expand;
	char	*errnum;
	int		size;

	size = ft_strlen(token) - 2 + 11 + 1;
	expand = malloc(size);
	if (expand == NULL)
		return (NULL);
	*pos = '\0';
	pos += 2;
	if (ft_strncmp("${?}", pos, 4) == 0)
		pos += 2;
	ft_strlcpy(expand, token, size);
	errnum = ft_itoa(env->ret);
	ft_strlcat(expand, errnum, size);
	free(errnum);
	*next_pos = ft_strchr(expand, '\0');
	ft_strlcat(expand, pos, size);
	return (expand);
}