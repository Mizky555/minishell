/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 08:28:20 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/16 19:58:02 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_struct.h"
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
	printf("line: %s\n", line);
	token_clear(&env->token);
	free(line);
	env->ret = 258;
	return (EXIT_FAILURE);
}

int	lexer(char *line, t_env *env)
{
	if (space_spliter(line, env))
		return (error_exit(line, env));
	if (redirect_spliter(env))
		return (error_exit(line, env));
	expand_tilde(env);
	if (!expand_variable_tokens(env))
		return (error_exit(line, env));
	token_print(env->token);
	return (EXIT_SUCCESS);
}