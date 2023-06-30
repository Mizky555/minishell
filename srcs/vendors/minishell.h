/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:02:11 by tliangso          #+#    #+#             */
/*   Updated: 2023/05/31 10:57:07 by tliangso         ###   ########.fr       */
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

#endif