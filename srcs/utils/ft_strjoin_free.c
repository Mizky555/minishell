/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:38:50 by tliangso          #+#    #+#             */
/*   Updated: 2023/05/30 21:57:20 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

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