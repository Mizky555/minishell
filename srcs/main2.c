/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:32:11 by thanapornsi       #+#    #+#             */
/*   Updated: 2023/07/29 22:59:34 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_line(char *line, t_env *env)
{
	if (lexer(line, env))
		return (EXIT_FAILURE);
	if (type_check(env))
		return (error_exit(line, env));
	if (quote_cleaner(env))
		return (error_exit(line, env));
	return (EXIT_SUCCESS);
}
