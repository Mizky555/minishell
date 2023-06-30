/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 08:28:20 by tliangso          #+#    #+#             */
/*   Updated: 2023/06/12 11:18:10 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int8_t	perror_exit(char *line, t_env *env)
{
	ft_putstr_fd("minishell: parse error\n", STDERR_FILENO);
	token_clear(&env->token);
	free(line);
	env->ret = 258;
	return (EXIT_FAILURE);
}

int8_t	error_exit(char *line, t_env *env)
{
	token_clear(&env->token);
	free(line);
	env->ret = 258;
	return (EXIT_FAILURE);
}

int	lexer(char *line, t_env *env)
{
	if (space_spliter(line, env))
		return (error_exit(line, env));
	return (EXIT_SUCCESS);
}