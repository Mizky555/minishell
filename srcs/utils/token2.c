/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:38:44 by tliangso          #+#    #+#             */
/*   Updated: 2023/05/31 10:56:31 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_size(t_token *lst)
{
	size_t	size;
	t_token	*node;

	node = lst;
	size = 0;
	while (node != NULL)
	{
		node = node->next;
		size++;
	}
	return (size);
}

void	token_delone(t_token *token)
{
	if (token != NULL)
	{
		if (token->token)
			free(token->token);
		free(token);
	}
}

void	token_del(t_token *token)
{
	if (token == NULL)
		return ;
	if (token->prev)
		token->prev->next = token->next;
	if (token->next)
		token->next->prev = token->prev;
	token_delone(token);
}

void	token_remove(t_token *head, int index)
{
	int		size;
	t_token	*tmp;

	size = token_size(head);
	if (index < 0 || index > size)
		return ;
	tmp = head;
	while (index--)
		tmp = tmp->next;
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	token_delone(tmp);
}

void	token_print(t_token *head)
{
	while (head)
	{
		printf("===============\n");
		printf("token:%s$\n", head->token);
		printf("type: %d\n", head->type);
		printf("quote: %d\n", head->quote);
		printf("===============\n");
		head = head->next;
	}
}
