/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:16:37 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/16 23:22:10 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_print(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(127);
}

void	error_print2(char *message1, char *message2)
{
	ft_putstr_fd(message1, STDERR_FILENO);
	error_print(message2);
}

void	error_exit_pipex(void)
{
	perror(NULL);
	exit(EXIT_FAILURE);
}

void	mini_end_exit(void *arg, t_process *proc)
{
	t_env	*env;

	env = (t_env *)arg;
	end_minishell(env);
	exit(proc->status);
}
