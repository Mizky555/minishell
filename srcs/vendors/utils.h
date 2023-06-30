/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:43:04 by tliangso          #+#    #+#             */
/*   Updated: 2023/05/31 10:56:39 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include <stdint.h>
# include "minishell_struct.h"

char	*ft_strjoin_free_n(char *str1, char *str2, int mode);

bool	ft_isspace(char c);
void	skip_whitespace(char **line);

int		nta_size(void **array);
void	nta_free(void **array);
void	**nta_new(void *p);
void	**nta_add_back(void **array, void *p);
void	**nta_add_front(void **array, void *p);

int		str_arr2_size(char	**split);
char	**str_arr2_addback(char **words, char *string);
void	str_arr2_delfront(char **words);
char	**str_arr2_dup(char **words);

t_token	*token_new(char *content, int type);
void	token_addback(t_token **lst, t_token *new);
void	token_addfront(t_token **lst, t_token *new);
int		token_clear(t_token **lst);
int		token_insert(t_token **head, t_token *new, int index);
int		token_size(t_token *lst);
void	token_delone(t_token *token);
void	token_del(t_token *token);
void	token_remove(t_token *head, int index);

void	token_print(t_token *head);

int8_t	perror_exit(char *line, t_env *env);
int8_t	error_exit(char *line, t_env *env);

#endif