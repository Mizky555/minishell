/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:37:35 by tliangso          #+#    #+#             */
/*   Updated: 2023/05/31 21:31:13 by tliangso         ###   ########.fr       */
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

void	token_addback(t_token **lst, t_token *new) //(หัว,ตัวทื่จะต่อ)
{
	t_token	*node;

	if (new == NULL)
		return ;
	node = *lst; // หัวของlineklist
	if (node != NULL) // ถ้าตัวแรกไม่มีอะไรเลย จะลงไป else จะกำหนด new ที่รับเข้ามาให้เป็นตัวแรกในlink(หัว)
	{
		while (node->next != NULL)
			node = node->next;//ขยับจนกว่าจะไปถึงตัวสุดท้าย
		node->next = new;//ให้ตัวหน้าก่อนชี้ไปตัวใหม่
		new->prev = node;//ให้ตัวใหม่ชี้ไปตัวก่อนหน้า
	}
	else
		*lst = new;
}

void	token_addfront(t_token **lst, t_token *new) //(หัว,ตัวใหม่ที่จะต่อด้านหน้า)
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


int	token_insert(t_token **head, t_token *new, int index) //แทรกlinklist (หัว,ตัวใหม่,ตำแหน่งที่อยากจะแทรก)
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