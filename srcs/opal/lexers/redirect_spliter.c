/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_spliter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:59:23 by thanapornsi       #+#    #+#             */
/*   Updated: 2023/07/27 01:33:14 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	len_token(t_token *token)
{
	t_token	*tmp;
	int		len;

	len = 0;
	tmp = token;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int	check_redirect(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (c == 0 && (str[i] == '\'' || str[i] == '\"'))
		{
			c = str[i];
		}
		else if (str[i] == c)
		{
			c = 0;
		}
		else if (str[i] == '<' || str[i] == '>' || str[i] == '|')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

t_token	*redirect_spliter2(char *str, t_env *env, t_token *tmp)
{
	t_token	*token;

	while (ft_strlen(str) > env->i)
	{
		if (get_check(str[env->i]) == 1)
			token = token_new(get_alpha(str + env->i, env), EMPTY);
		else
			token = token_new(get_redirect(str + env->i, env), EMPTY);
		token_insert(&env->token, token, env->index++);
		env->i += ft_strlen(token->token);
	}
	if (tmp->next)
	{
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
	}
	else
		tmp->prev->next = NULL;
	return (tmp);
}

bool	redirect_spliter(t_env *env)
{
	t_token	*tmp;
	t_token	*del;
	char	*str;

	tmp = env->token;
	while (tmp)
	{
		str = tmp->token;
		env->i = 0;
		if (check_redirect(str))
		{
			del = redirect_spliter2(str, env, tmp);
			tmp = tmp->next;
			free(del->token);
			free(del);
		}
		else
		{
			tmp = tmp->next;
			env->index++;
		}
	}
	return (0);
}

int	get_check(char c)
{
	if (c == '>' || c == '<' || c == '|')
		return (0);
	return (1);
}
