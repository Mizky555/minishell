/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:11:59 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/17 13:25:52 by tliangso         ###   ########.fr       */
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

int	minishell_term(t_env *env) //ไว้สำหรับทำ env terminal
{
	env->term = (t_term *)malloc(sizeof(t_term)); //ไว้เก็บ env ของ terminal
	if (env->term == NULL)
		return (EXIT_FAILURE);
	tcgetattr(STDIN_FILENO, &env->term->minishell);//attr ของเทอร์มินอล 
	tcgetattr(STDIN_FILENO, &env->term->shell);//เอิ้ดทำ
	// env->term->minishell.c_lflag &= ~ECHOCTL;
	// env->term->shell.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &env->term->minishell);//การเปลี่ยนแปลงจเกกิดขึ้นหลังจากการส่ง
	return (EXIT_SUCCESS);
}

void	end_minishell(t_env *env) // เคีลยโปรแกรม
{
	rl_clear_history(); // เคลียประวัติ cmd ขึ้นลง
	environ = env->tmp_environ; // 
	nta_free((void **)env->dup_environ);
	token_clear(&env->token);
	free(env->term);
}

bool	init_minishell(t_env *env) //ถ้าวิ่งได้ 0 วิ่งไม่ได้ 1 หาไม่เจอ 127
{
	env->ret = 0; //return signal ของแต่ละคอมมาน
	env->exit = 1; //สำหรับ exit command
	env->cmd_counts = 1; //นับว่ามี command กี่ตัว
	env->token = NULL; //ไว้ init pointer เป็น null
	env->files = NULL; //init pointer
	env->pipex_cmds = NULL;
	if (minishell_term(env) == EXIT_FAILURE)//terminfo ข้อมูลของเทอมินอล
	{
		perror("minishell"); // ถ้ามี error จะ print ใน "" และต่อด้วยที่ error
		end_minishell(env);
		exit(EXIT_FAILURE); //คืนค่าที่ไม่เท่ากับ 0
	}
	env->errorchar = '\0';
	env->tmp_environ = environ; //ต้นฉบับเราจะไม่แก้ไข (ใช้อีกทีตอนจบโปรแกรมเลย)
	env->dup_environ = str_arr2_dup(environ); //cpy ต้นฉบับ
	environ = env->dup_environ; // เอาตัว cpy เก็บไว้ในตัวแปรพิเศษ eviron ทำให้สามารถใช้ environ แก้ไขได้
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
	return (EXIT_FAILURE); //คืนค่าที่ไม่เท่ากับ 0
}


int	process_line(char *line, t_env *env)
{
	if (lexer(line, env))
		return (EXIT_FAILURE); //สร้าง แอควาลอนเม้น
	// printf("\n\n\n");
	if (type_check(env))
		return (error_exit(line, env));
	// printf("type\n");
	// token_print(env->token);
	return (EXIT_SUCCESS);
}

int	main(void)
{
	t_env	env;
	char	*line;

	init_minishell(&env);
	while (true)
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
	return (env.exit);
}

// char	*make_prompt(t_env *env)
// {
// 	char	*cwd;
// 	char	*home;
// 	char	*name;
// 	char	*tmp;

// 	cwd = getcwd(NULL, 0);
// 	home = getenv("HOME");
// 	if (home == NULL)
// 		home = "";
// 	name = getenv("USER");
// 	if (name == NULL)
// 		name = "";
// 	if (ft_strncmp(cwd, home, ft_strlen(home)) == 0)
// 	{
// 		tmp = ft_strjoin("~", cwd + ft_strlen(home));
// 		free(cwd);
// 		cwd = tmp;
// 	}
// 	name = ft_strjoin_free_n(name, "@minishell: ", 0);
// 	cwd = ft_strjoin_free_n(name, cwd, 3);
// 	cwd = ft_strjoin_free_n("\033[30;1;7m\033[1;47m ", cwd, 2);
// 	cwd = ft_strjoin_free_n(cwd, "\033[0m [", 1);
// 	cwd = ft_strjoin_free_n(cwd, ft_itoa(env->ret), 3);
// 	cwd = ft_strjoin_free_n(cwd, "]> \0", 1);
// 	return (cwd);
// }