/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_spliter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:25:19 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/26 23:59:05 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	get_token_size(char *line)
{
	size_t	len;
	char	c;

	len = 0;
	c = 0;
	while (*line && (*line != ' ' || c != 0))
	{
		if (c == 0 && (*line == '\'' || *line == '\"'))
			c = *line;
		else if (*line == c)
			c = 0;
		line++;
		len++;
	}
	return (len);
}

static char	*get_token(char *line, int *error)
{
	char	*token;
	int		i;
	char	c;

	i = 0;
	c = 0;
	token = (char *)malloc(get_token_size(line) + 1);
	if (!token)
		return (NULL);
	while (*line && (*line != ' ' || c))
	{
		if (c == 0 && (*line == '\'' || *line == '\"'))
			c = *line;
		else if (c == *line)
			c = 0;
		token[i++] = *line++;
	}
	token[i] = '\0';
	if (c != 0)
	{
		free(token);
		*error = 1;
		return (NULL);
	}
	return (token);
}

bool	space_spliter(char *line, t_env *env)
{
	t_token	*token;
	int		error;

	error = 0;
	skip_whitespace(&line);
	while (*line)
	{
		skip_whitespace(&line);
		token = token_new(get_token(line, &error), EMPTY);
		if (token == NULL)
		{
			if (error == 1)
				ft_putstr_fd("miniopal: parse error\n", 2);
			return (token_clear(&env->token));
		}
		token_addback(&env->token, token);
		if (!*line)
			break ;
		line = line + ft_strlen(token->token);
		skip_whitespace(&line);
	}
	return (EXIT_SUCCESS);
}
