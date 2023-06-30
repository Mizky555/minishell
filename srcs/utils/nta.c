/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nta.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:42:09 by tliangso          #+#    #+#             */
/*   Updated: 2023/05/30 23:00:01 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	nta_size(void **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

void	nta_free(void **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	**nta_new(void *p)
{
	void	**array;

	array = malloc(sizeof(void *) * 2);
	if (array == NULL)
		return (NULL);
	array[0] = p;
	array[1] = NULL;
	return (array);
}

void	**nta_add_back(void **array, void *p)
{
	void	**array2;
	int		size;
	int		i;

	if (p == NULL)
		return (NULL);
	if (array == NULL)
		return (nta_new(p));
	size = nta_size(array);
	array2 = malloc(sizeof(void *) * (size + 2));
	if (array2 == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array2[i] = array[i];
		i++;
	}
	array2[i] = p;
	array2[i + 1] = NULL;
	free(array);
	return (array2);
}

void	**nta_add_front(void **array, void *p)
{
	void	**array2;
	int		size;
	int		i;

	if (array == NULL)
		return (nta_new(p));
	size = nta_size(array);
	array2 = malloc(sizeof(void *) * (size + 2));
	if (array2 == NULL)
		return (NULL);
	array2[0] = p;
	i = 0;
	while (i < size)
	{
		array2[i + 1] = array[i];
		i++;
	}
	array2[i + 1] = NULL;
	free(array);
	return (array2);
}