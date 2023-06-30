/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:11:59 by tliangso          #+#    #+#             */
/*   Updated: 2023/05/31 21:28:47 by tliangso         ###   ########.fr       */
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
	// env->term->minishell.c_lflag &= ~ECHOCTL;
	// env->term->shell.c_lflag |= ECHOCTL;
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

	env->ret = 0;
	env->exit = 0;
	return (EXIT_FAILURE);
}

char	*make_prompt(t_env *env)
{
	char	*cwd;
	char	*home;
	char	*name;
	char	*tmp;

	cwd = getcwd(NULL, 0);
	home = getenv("HOME");
	if (home == NULL)
		home = "";
	name = getenv("USER");
	if (name == NULL)
		name = "";
	if (ft_strncmp(cwd, home, ft_strlen(home)) == 0)
	{
		tmp = ft_strjoin("~", cwd + ft_strlen(home));
		free(cwd);
		cwd = tmp;
	}
	name = ft_strjoin_free_n(name, "@minishell: ", 0);
	cwd = ft_strjoin_free_n(name, cwd, 3);
	cwd = ft_strjoin_free_n("\033[30;1;7m\033[1;47m ", cwd, 2);
	cwd = ft_strjoin_free_n(cwd, "\033[0m [", 1);
	cwd = ft_strjoin_free_n(cwd, ft_itoa(env->ret), 3);
	cwd = ft_strjoin_free_n(cwd, "]> \0", 1);
	return (cwd);
}

void	process_line(char *line, t_env *env)
{
	lexer(line, env);
	token_print(env->token);
	// parser(env);
	// executor(env);
}

int	main(void)
{
	t_env	env;
	char	*prompt;
	char	*line;

	prompt = NULL;
	init_minishell(&env);
	while (true)
	{
		prompt = make_prompt(&env);
		line = readline(prompt);
		free(prompt);
		if (line == NULL)
			break ;
		add_history(line);
		process_line(line, &env);
		free(line);
		token_clear(&env.token);
	}
	end_minishell(&env);
	return (env.exit);
}