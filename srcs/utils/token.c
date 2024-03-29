/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:37:35 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/27 00:05:14 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_new(char *content, int type)
{
	t_token	*new_node;

	if (content == NULL)
		return (NULL);
	new_node = (t_token *)malloc(sizeof(t_token));
	if (new_node == NULL)
		return (NULL);
	new_node->token = content;
	new_node->type = type;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	token_addback(t_token **lst, t_token *new)
{
	t_token	*node;

	if (new == NULL)
		return ;
	node = *lst;
	if (node != NULL)
	{
		while (node->next != NULL)
			node = node->next;
		node->next = new;
		new->prev = node;
	}
	else
		*lst = new;
}

void	token_addfront(t_token **lst, t_token *new)
{
	if (*lst != NULL && new != NULL)
	{
		new->next = *lst;
		(*lst)->prev = new;
		*lst = new;
	}
	else if (new != NULL)
		*lst = new;
}

int	token_clear(t_token **lst)
{
	t_token	*cur;
	t_token	*next;

	if (lst == NULL)
		return (1);
	cur = *lst;
	while (cur != NULL)
	{
		next = cur->next;
		free(cur->token);
		free(cur);
		cur = next;
	}
	*lst = NULL;
	return (1);
}

int	token_insert(t_token **head, t_token *new, int index)
{
	int		size;
	t_token	*tmp;

	if (new == NULL)
		return (1);
	size = token_size(*head);
	if (index < 0 || index > size)
		return (1);
	else if (head == NULL)
		*head = new;
	else if (index == 0)
		token_addfront(head, new);
	else if (index == size)
		token_addback(head, new);
	else
	{
		tmp = *head;
		while (--index)
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next->prev = new;
		new->prev = tmp;
		tmp->next = new;
	}
	return (0);
}
