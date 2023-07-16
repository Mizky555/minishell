/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:02:11 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/16 19:56:29 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

// own header
# include	"libft.h"
# include	"utils.h"
# include	"minishell_struct.h"
# include	"minishell_define.h"

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

#endif