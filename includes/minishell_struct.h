/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:29:52 by tliangso          #+#    #+#             */
/*   Updated: 2023/05/30 22:30:47 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

# include <term.h>
# include <signal.h>

typedef struct sigaction	t_sigact;

// struct
typedef struct s_token
{
	int	i_insert;
	char			*token; // คำที่แยก
	int				type; //แต่ละ token เป็นประเภทไหน
	struct s_token	*next; //ตัวถัดไป
	struct s_token	*prev; //ตัวก่อนหน้า
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

typedef struct s_env // ศูนย์เก็บข้อมูลกลาง ไว้เก็บ struct และอื่นๆ
{
	t_token				*token;//หัว
	t_token				*cur_token; //passer
	char				***pipex_cmds; //execute
	char				***files; //execute
	int					ret; //util +exe
	int					exit;//util
	int					cmd_counts; //exe
	char				**tmp_environ;//pas
	char				**dup_environ;//pas
	t_term				*term;//util
	char				errorchar;//util
	t_sigact			sigint;//uti
	t_sigact			sigquit;//uti

}	t_env;

#endif