/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:29:52 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/30 20:50:16 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

# include <term.h>
# include <signal.h>

typedef struct sigaction	t_sigact;
typedef struct s_token
{
	int				i_insert;
	char			*token;
	int				type;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_runner
{
	int		i;
	int		j;
	char	c;
	char	*deqstr;
}	t_runner;

typedef struct s_term
{
	struct termios	minishell;
	struct termios	shell;
}	t_term;

typedef struct s_env
{
	t_token				*token;
	t_token				*cur_token;
	char				***pipex_cmds;
	char				***files;
	int					ret;
	int					exit;
	char				**tmp_environ;
	char				**dup_environ;
	t_term				*term;
	char				errorchar;
	t_sigact			sigint;
	t_sigact			sigquit;
	size_t				i;
	int					index;
	char				**environ;

}	t_env;

#endif
