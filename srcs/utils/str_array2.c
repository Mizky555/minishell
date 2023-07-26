/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_array2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanapornsirirakwongsa <thanapornsirira    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:58:55 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/27 00:04:10 by thanapornsi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int	str_arr2_size(char	**split)
{
	int	len;

	len = 0;
	while (split[len] != NULL)
		len++;
	return (len);
}

char	**str_arr2_addback(char **words, char *string)
{
	char	**join;
	int		size;
	int		i;

	if (words == NULL || string == NULL)
		return (NULL);
	size = str_arr2_size(words);
	join = malloc(sizeof(char **) * (size + 2));
	if (join == NULL)
		return (NULL);
	join[size] = ft_strdup(string);
	if (join[size] != NULL)
	{
		i = 0;
		while (words[i] != NULL)
		{
			join[i] = words[i];
			i++;
		}
		join[size + 1] = NULL;
		free(words);
		return (join);
	}
	free(join);
	return (NULL);
}

void	str_arr2_delfront(char **words)
{
	int	i;

	if (words != NULL)
	{
		if (words[0] != NULL)
			free(words[0]);
		i = 0;
		while (words[i] != NULL)
		{
			words[i] = words[i + 1];
			i++;
		}
	}
}

char	**str_arr2_dup(char **words)
{
	char	**dup;
	int		size;
	int		i;

	if (words == NULL)
		return (NULL);
	size = str_arr2_size(words);
	dup = malloc(sizeof(char **) * (size + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dup[i] = ft_strdup(words[i]);
		if (dup[i] == NULL)
		{
			nta_free((void **)dup);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
