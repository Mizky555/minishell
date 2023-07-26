/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:21:30 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/27 00:16:57 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
//        The  memset()  function  fills the first n bytes of the memory
//        area pointed to by s with the constant byte c.
//
// RETURN VALUE
//        The memset() function returns a pointer to the memory area s.
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*(unsigned char *)(s + i++) = (char)(c);
	return (s);
}
