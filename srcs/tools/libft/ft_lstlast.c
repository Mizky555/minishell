/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:01:56 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/27 00:16:05 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PARAMETERS
// lst: The beginning of the list.

// DESCRIPTION
// Returns the last node of the list.

// RETURN VALUE
// Last node of the list

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	node = lst;
	while (node != NULL && node->next != NULL)
		node = node->next;
	return (node);
}
