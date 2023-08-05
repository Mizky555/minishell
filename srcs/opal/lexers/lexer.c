/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 08:28:20 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/29 22:59:13 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_struct.h"
#include "minishell.h"

int8_t	perror_exit(char *line, t_env *env)
{
	ft_putstr_fd("miniopal: parse error\n", STDERR_FILENO);
	token_clear(&env->token);
	free(line);
	env->ret = 258;
	return (EXIT_FAILURE);
}

int8_t	error_exit(char *line, t_env *env)
{
	printf("!! Error :3!!\n");
	token_clear(&env->token);
	free(line);
	env->ret = 258;
	return (EXIT_FAILURE);
}

int	lexer(char *line, t_env *env)
{
	env->index = 0;
	if (space_spliter(line, env))
		return (error_exit(line, env));
	if (redirect_spliter(env))
		return (error_exit(line, env));
	expand_tilde(env);
	if (expand_variable_tokens(env))
		return (error_exit(line, env));
	return (EXIT_SUCCESS);
}
