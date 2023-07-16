/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 08:28:20 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/16 23:36:17 by tliangso         ###   ########.fr       */
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
	printf("space\n");
	token_print(env->token);
	printf("\n\n\n");
	if (redirect_spliter(env))
		return (error_exit(line, env));
	printf("redirect\n");
	token_print(env->token);
	printf("\n\n\n");
	expand_tilde(env);
	if (expand_variable_tokens(env))
		return (error_exit(line, env));
	printf("variable\n");
	token_print(env->token);
	printf("\n\n\n");
	if (type_check(env))
		return (error_exit(line, env));
	printf("type\n");
	token_print(env->token);
	return (EXIT_SUCCESS);
}