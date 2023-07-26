/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:49:34 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/27 00:15:44 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PARAMETERS
// lst: The address of a pointer to the first link of a list.
// new: The address of a pointer to the node to be added to the list.

// DESCRIPTION
// Adds the node ’new’ at the beginning of the list.

// RETURN VALUE
// None

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
	else if (new != NULL)
		*lst = new;
}
