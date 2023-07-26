/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:32:11 by thanapornsi       #+#    #+#             */
/*   Updated: 2023/07/27 00:32:14 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_line(char *line, t_env *env)
{
	if (lexer(line, env))
		return (EXIT_FAILURE);
	if (type_check(env))
		return (error_exit(line, env));
	return (EXIT_SUCCESS);
}
