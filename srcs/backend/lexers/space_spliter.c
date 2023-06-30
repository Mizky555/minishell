/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_spliter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:25:19 by tliangso          #+#    #+#             */
/*   Updated: 2023/05/31 21:27:27 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	get_token_size(char *line)
{
	size_t	len;
	char	c;

	len = 0;
	c = 0;
	while (*line && (*line != ' ' || c))
	{
		if (!c && (*line == '\'' || *line == '\"'))
			c = *line;
		else if (c && *line == c)
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
	token[i] = 0;
	if (c)
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
		token = token_new(get_token(line, &error), EMPTY);
		if (token == NULL)
		{
			if (error)
				ft_putstr_fd("minishell: parse error\n", 2);
			return (token_clear(&env->token));
		}
		skip_whitespace(&line);
		token_addback(&env->token, token);
		if (!*line)
			break ;
		printf("%s\n", line);
		line = line + ft_strlen(token->token);
	}
	return (EXIT_SUCCESS);
}