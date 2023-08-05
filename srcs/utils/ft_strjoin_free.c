/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:38:50 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/27 00:04:02 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_n(char *str1, char *str2, int mode)
{
	char	*ret;

	ret = ft_strjoin(str1, str2);
	if (str1 && mode != 2 && mode != 0)
		free(str1);
	if (str2 && mode != 1 && mode != 0)
		free(str2);
	return (ret);
}
