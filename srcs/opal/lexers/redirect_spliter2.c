/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_spliter2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:30:38 by thanapornsi       #+#    #+#             */
/*   Updated: 2023/07/27 01:35:12 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_alpha(char *token, t_env *env)
{
	char	*alpha;
	char	c;
	int		i;
	int		index;

	i = 0;
	c = 0;
	index = 0;
	alpha = (char *)malloc(get_alpha_size(token) + 1);
	if (!alpha)
		return (NULL);
	while (token[i])
	{
		if ((token[i] == '<' || token[i] == '>' || token[i] == '|') && c == 0)
			break ;
		else if ((token[i] == '\'' || token[i] == '\"') && c == 0)
			c = token[i];
		else if (token[i] == c)
			c = 0;
		alpha[index++] = token[i++];
	}
	alpha[index] = '\0';
	env->token->i_insert++;
	return (alpha);
}

char	*get_redirect(char *token, t_env *env)
{
	char	*redirect;
	char	c;
	int		i;

	i = 0;
	c = 0;
	redirect = (char *)malloc(get_redirect_size(token) + 1);
	if (!redirect)
		return (NULL);
	if (token[i] == '<' || token[i] == '>')
	{
		redirect[i] = token[i];
		c = token[i];
		i++;
		if (token[i] == c)
		{
			redirect[i] = token[i];
			i++;
		}
	}
	else if (token[i] == '|')
		redirect[i++] = '|';
	redirect[i] = '\0';
	env->token->i_insert++;
	return (redirect);
}

size_t	get_redirect_size(char *token)
{
	char	c;
	int		i;

	c = 0;
	i = 0;
	if (token[i] == '<' || token[i] == '>')
	{
		c = token[i];
		i++;
		if (token[i] == c)
			i++;
	}
	else if (token[i] == '|')
		i++;
	return (i);
}

size_t	get_alpha_size(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && c == 0)
		{
			c = str[i];
		}
		else if ((str[i] == '<' || str[i] == '>' || str[i] == '|') && c == 0)
		{
			return (i);
		}
		else if (str[i] == c)
		{
			c = 0;
		}
		i++;
	}
	return (i);
}
