/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:02:11 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/17 13:23:13 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

// own header
# include	"libft.h"
# include	"utils.h"
# include	"minishell_struct.h"
# include	"minishell_define.h"
# include	"process.h"

// std header
# include	<stdbool.h>
# include	<stdint.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<sys/wait.h>
# include	<unistd.h>
# include	<readline/readline.h>
# include	<readline/history.h>
# include	<errno.h>
# include	<term.h>
# include	<signal.h>
# include	<string.h>
# include	<fcntl.h>

# if __linux__
#  include	<linux/limits.h>
# endif

extern char	**environ;

bool	space_spliter(char *line, t_env *env);
int		lexer(char *line, t_env *env);
bool	redirect_spliter(t_env *env);
char	*get_alpha(char *token, t_env *env);
size_t	get_alpha_size(char *token);
char	*get_redirect(char *token, t_env *env);
size_t	get_redirect_size(char *token);
int		get_check(char c);
char	*expand_var(char *token, char *pos, char **next_pos);
char	*expand_error(t_env *env, char *token, char *pos, char **next_pos);
char	*expand_brace(char *token, char *pos, char **next_pos);
int		expand_variable_tokens(t_env *env);
void	expand_tilde(t_env *env);
int		type_check(t_env *env);
void	end_minishell(t_env *env);
char	*read_here_doc(char *limiter);
char	*get_pathname(char *cmd, char **envp);
void	close_files(t_io **ios);
int		open_files(t_io **ios, int type);
t_io	**add_file(t_io **ios, char *filename, int type, char *limiter);
void	free_files(t_io **ios);
char	*get_next_line(int fd);
int		run_pipe(t_env *env);
void	ft_split_free(char **words);
int		args_exec(t_env *env, t_process **procs);
int ft_env(void);
//cd.c
int ft_cd(char **argv);
//echo.c
int ft_echo(char **argv);
int argv_len(char **argv);
//ped.c
int ft_pwd(void);
//export.c
int ft_export(t_env *env, char **argv);
void    add_env(t_env *env, char *argv);
int check_env(char *environ, char *argv);
int index_equal(char *str);
char    **sort_env(void);
void	print_and_free(char **new_env);
void    add_new_env(t_env *env, char *argv);
int len_arr2(char **str);
int	ft_strcmp(char *s1, char *s2);
//exit.c
int	ft_exit(t_env *env, char **argv);
//unset.c
int ft_unset(t_env *env, char **argv);
int    unset_env(t_env *env, char *argv);
int	env_vs_argv(char *argv, char *env);

#endif