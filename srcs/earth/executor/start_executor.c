/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_executor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:17:54 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/17 13:18:11 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**parse_command(t_env *env, int n)
{
	int		cmd_n;
	char	**cmd;
	t_token	*tok;

	cmd_n = 0;
	cmd = NULL;
	tok = env->token;
	while (tok != NULL)
	{
		if (tok->type == PIPE)
			cmd_n++;
		if (cmd_n == n && (tok->type == CMD || tok->type == ARG))
			cmd = (char **)nta_add_back((void **)cmd, ft_strdup(tok->token));
		tok = tok->next;//nta_add_back เหมือน str_arr2_addback
	}
	return (cmd);
}

/*
 * parse all io from command n in t_env
 */
static t_io	**parse_io(t_env *env, int n)//เอามาอ่านไฟลแล้วเตรียมเขียนหรืออ่าน
{
	int		cmd_n;
	t_token	*tok;
	t_io	**io;

	io = NULL;
	cmd_n = 0;
	tok = env->token;
	while (tok != NULL)//วิ่งจนตัวสุดท้าย
	{
		if (tok->type == PIPE)
			cmd_n++;
		if (cmd_n == n && (tok->type & (INPUT | FPATH)) == (INPUT | FPATH))
			io = add_file(io, tok->token, IO_READ, NULL);
		else if (cmd_n == n
			&& (tok->type & (HEREDOC | FPATH)) == (HEREDOC | FPATH))
			io = add_file(io, NULL, IO_HEREDOC, tok->token);
		else if (cmd_n == n && (tok->type & (TRUNC | FPATH)) == (TRUNC | FPATH))
			io = add_file(io, tok->token, IO_TRUNC, NULL);
		else if (cmd_n == n
			&& (tok->type & (APPEND | FPATH)) == (APPEND | FPATH))
			io = add_file(io, tok->token, IO_APPEND, NULL);
		tok = tok->next;
	}
	return (io);
}

/*
 * special case if pipe has io but no commands
 */
static char	**nocmd_special(void)
{
	char		**echo;

	echo = (char **)nta_add_back(NULL, (void *)ft_strdup("echo"));
	echo = (char **)nta_add_back((void **)echo, (void *)ft_strdup("-n"));
	return (echo);
}

static t_process	**build_pipex(t_env *env)
{
	t_process	**procs;
	t_io		**ios;
	char		**cmd;
	int			n;

	n = 0;
	procs = NULL;
	cmd = parse_command(env, n);
	ios = parse_io(env, n); //inout outout (ไฟล < > เข้าหรือออก และ >>,<<)
	if (cmd == NULL && ios != NULL)
		cmd = nocmd_special();
	while (cmd != NULL)
	{
		procs = add_proc(procs, cmd, environ);
		nta_free((void **)cmd);
		procs[n]->io = ios;
		n++;
		cmd = parse_command(env, n);
		ios = parse_io(env, n);
		if (cmd == NULL && ios != NULL)
			cmd = nocmd_special();
	}
	return (procs);
}

int	run_pipe(t_env *env)
{
	t_process	**procs;
	int			status;

	procs = build_pipex(env);
	if (procs == NULL)
		return (0);
	init_pipex(procs);
	status = args_exec(env, procs);
	free_pipex(procs);
	return (status);
}
