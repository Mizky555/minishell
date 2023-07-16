/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:56:02 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/16 19:56:17 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_tilde(t_env *env)
{
	t_token	*tok;

	tok = env->token;
	while (tok != NULL)
	{
		if (ft_strncmp(tok->token, "~", 2) == 0)
		{
			free(tok->token);
			tok->token = ft_strdup("$HOME");
		}
		tok = tok->next;
	}
}