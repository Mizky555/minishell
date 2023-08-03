/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:19:29 by tliangso          #+#    #+#             */
/*   Updated: 2023/08/03 11:21:05 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signal(t_env *env)
{
	env->sigint.sa_handler = SIG_DFL;
	sigemptyset(&env->sigint.sa_mask);
	env->sigint.sa_flags = SA_RESTART;
	sigaction(SIGINT, &env->sigint, NULL);
	env->sigquit.sa_handler = SIG_DFL;
	sigemptyset(&env->sigquit.sa_mask);
	env->sigquit.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &env->sigquit, NULL);
}
