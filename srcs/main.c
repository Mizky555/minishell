/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:11:59 by tliangso          #+#    #+#             */
/*   Updated: 2023/08/03 11:30:58 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	nta_free((void **)env->dup_environ);
	token_clear(&env->token);
	free(env->term);
}

bool	init_minishell(t_env *env)
{
	env->ret = 0;
	env->exit = 1;
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
	env->dup_environ = str_arr2_dup(env->environ);
	env->environ = env->dup_environ;
	init_signal(env);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	t_env	env;
	char	*line;

	(void)argc;
	(void)argv;
	env.environ = envp;
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
		init_signal(&env);
	}
	end_minishell(&env);
	return (env.ret);
}
