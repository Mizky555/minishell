/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qoute_remover.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:06:52 by tliangso          #+#    #+#             */
/*   Updated: 2023/08/02 23:58:26 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	remove_quote(t_token *tok)
{
	char	*newtoken;
	int		i;
	int		is_quoted;
	int		new_i;

	new_i = 0;
	i = -1;
	is_quoted = 0;
	newtoken = ft_calloc(ft_strlen(tok->token) + 1, sizeof(char));
	if (!newtoken)
		return (1);
	while (++i < (int)ft_strlen(tok->token))
	{
		if ((tok->token[i] == '\'' || tok->token[i] == '\"') 
			&& (is_quoted == tok->token[i] || is_quoted == 0))
		{
			if (is_quoted && (is_quoted == tok->token[i]))
				is_quoted = 0;
			else if (is_quoted == 0)
				is_quoted = tok->token[i];
		}
		else
			newtoken[new_i++] = tok->token[i];
	}
	return (free(tok->token), tok->token = newtoken, !is_quoted);
}

int	check_quote(t_token *tok)
{
	if (ft_strchr(tok->token, '\'') || ft_strchr(tok->token, '\"'))
		return (1);
	return (0);
}

int	quote_cleaner(t_env *env)
{
	t_token	*tmp;

	tmp = env->token;
	while (tmp)
	{
		if (check_quote(tmp))
			remove_quote(tmp);
		tmp = tmp->next;
	}
	return (0);
}
