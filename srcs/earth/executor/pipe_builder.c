/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:14:44 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/17 13:16:01 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*free_pipes(int **pipes)
{
	int	i;

	if (pipes != NULL)
	{
		i = 0;
		while (pipes[i] != NULL)
		{
			free(pipes[i]);
			i++;
		}
		free(pipes);
	}
	return (NULL);
}

int	**close_pipes(int **pipes)
{
	int	i;

	if (pipes != NULL)
	{
		i = 0;
		while (pipes[i] != NULL)
		{
			if (pipes[i][0] != -1)
				close(pipes[i][0]);
			if (pipes[i][1] != -1)
				close(pipes[i][1]);
			i++;
		}
	}
	return (pipes);
}

int	**make_pipes(int n)
{
	int	**pipes;
	int	i;

	if (n < 1)
		return (NULL);
	pipes = malloc(sizeof(int *) * (n + 1));
	if (pipes == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (pipes[i] == NULL)
			return (free_pipes(pipes));
		pipes[i][0] = -1;
		pipes[i][1] = -1;
		if (pipe(pipes[i]) != 0)
			return (free_pipes(close_pipes(pipes)));
		i++;
	}
	pipes[n] = NULL;
	return (pipes);
}
