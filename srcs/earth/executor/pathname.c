/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:22:32 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/17 13:21:49 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**get_path(char **envp)
{
	while (*envp != NULL)
	{
		if (ft_strncmp("PATH=", *envp, 5) == 0)
			return (ft_split((*envp) + 5, ':'));
		envp++;
	}
	return (NULL);
}

void	ft_split_free(char **words)
{
	int	i;

	if (words != NULL)
	{
		i = 0;
		while (words[i] != NULL)
		{
			free(words[i]);
			i++;
		}
		free(words);
	}
}

char	*get_pathname(char *cmd, char **envp)
{
	char	pathname[PATH_MAX];
	char	**path;
	int		i;

	if (access(cmd, X_OK) != -1)
		return (ft_strdup(cmd));
	i = 0;
	path = get_path(envp);
	while (path != NULL && path[i] != NULL)
	{
		ft_strlcpy(pathname, path[i], PATH_MAX);
		ft_strlcat(pathname, "/", PATH_MAX);
		ft_strlcat(pathname, cmd, PATH_MAX);
		if (access(pathname, X_OK) != -1)
			break ;
		ft_strlcpy(pathname, cmd, PATH_MAX);
		i++;
	}
	ft_split_free(path);
	return (ft_strdup(pathname));
}