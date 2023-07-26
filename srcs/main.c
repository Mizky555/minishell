/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:11:59 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/27 00:31:56 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	minishell_term(t_env *env)
{
	env->term = (t_term *)malloc(sizeof(t_term));
	if (env->term == NULL)
		return (EXIT_FAILURE);
	tcgetattr(STDIN_FILENO, &env->term->minishell);
	tcgetattr(STDIN_FILENO, &env->term->shell);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &env->term->minishell);
	return (EXIT_SUCCESS);
}

void	end_minishell(t_env *env)
{
	rl_clear_history();
	environ = env->tmp_environ;
	nta_free((void **)env->dup_environ);
	token_clear(&env->token);
	free(env->term);
}

bool	init_minishell(t_env *env)
{
	env->ret = 0;
	env->exit = 1;
	env->cmd_counts = 1;
	env->token = NULL;
	env->files = NULL;
	env->pipex_cmds = NULL;
	if (minishell_term(env) == EXIT_FAILURE)
	{
		perror("minishell");
		end_minishell(env);
		exit(EXIT_FAILURE);
	}
	env->errorchar = '\0';
	env->tmp_environ = environ;
	env->dup_environ = str_arr2_dup(environ);
	environ = env->dup_environ;
	env->sigint.sa_handler = sig_handler;
	sigemptyset(&env->sigint.sa_mask);
	env->sigint.sa_flags = SA_RESTART;
	sigaction(SIGINT, &env->sigint, NULL);
	env->sigquit.sa_handler = SIG_IGN;
	sigemptyset(&env->sigquit.sa_mask);
	env->sigquit.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &env->sigquit, NULL);
	return (EXIT_FAILURE);
}

int	main(void)
{
	t_env	env;
	char	*line;

	init_minishell(&env);
	while (env.exit)
	{
		line = readline("miniopal : ");
		if (line == NULL)
			break ;
		add_history(line);
		if (!process_line(line, &env))
			free(line);
		env.ret = run_pipe(&env);
		token_clear(&env.token);
	}
	end_minishell(&env);
	return (env.ret);
}
