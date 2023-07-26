/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qoute_remover.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:06:52 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/26 23:46:13 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	alloc_size(char *line)
{
	int		i;
	int		minus;
	char	c;

	i = 0;
	minus = 0;
	c = ' ';
	while (*(line + i) && (*(line + i) != ' ' || c != ' '))
	{
		if (c == ' ' && (*(line + i) == '\'' || *(line + i) == '\"'))
			c = *(line + i);
		else if (c != ' ' && *(line + i) == c)
		{
			minus += 2;
			c = ' ';
		}
		i++;
	}
	return (i - minus + 1);
}

void	init_runner(t_runner *r)
{
	r->i = 0;
	r->j = 0;
	r->c = ' ';
}

int	return_quote_func(t_token *t, t_runner *r)
{
	free(t->token);
	t->token = ft_strdup(r->deqstr);
	free(r->deqstr);
	return (0);
}

int	remove_quote(t_token *t)
{
	t_runner	r;

	init_runner(&r);
	r.deqstr = malloc(sizeof(char) * alloc_size(t->token));
	if (r.deqstr == NULL)
		return (1);
	while (*(t->token + r.i) && (*(t->token + r.i) != ' ' || r.c != ' '))
	{
		if (r.c == ' ' && (*(t->token + r.i) == '\''
				|| *(t->token + r.i) == '\"'))
			r.c = *(t->token + r.i++);
		else if (r.c != ' ' && *(t->token + r.i) == r.c)
		{
			r.i++;
			r.c = ' ';
		}
		else
			*(r.deqstr + r.j++) = *(t->token + r.i++);
	}
	*(r.deqstr + r.j) = '\0';
	return (return_quote_func(t, &r));
}

int	quote_cleaner(t_env *env)
{
	t_token	*tmp;

	tmp = env->token;
	while (tmp)
	{
		remove_quote(tmp);
		tmp = tmp->next;
	}
	return (0);
}
