/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:56:02 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/26 23:45:26 by thanapornsi      ###   ########.fr       */
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
