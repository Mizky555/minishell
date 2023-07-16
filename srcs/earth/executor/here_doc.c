/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:21:31 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/16 23:21:32 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	read_until_limiter(int fd_input, int fd_output, char *limiter)
{
	char	*line;
	int		size;
	char	*limiter2;

	size = ft_strlen(limiter);
	limiter2 = ft_strjoin(limiter, "\n");
	write(1, "> ", 2);
	line = get_next_line(fd_input);
	while (line != NULL)
	{
		if (ft_strncmp(limiter2, line, size + 2) == 0)
		{
			free(line);
			line = NULL;
		}
		else
		{
			ft_putstr_fd(line, fd_output);
			free(line);
			write(1, "> ", 2);
			line = get_next_line(fd_input);
		}
	}
	free(limiter2);
}

char	*read_here_doc(char *limiter)
{
	char	pathname[20];
	char	*number;
	int		fd;
	int		i;

	i = 1;
	while (i < 1000)
	{
		number = ft_itoa(i);
		ft_strlcpy(pathname, "/tmp/pipex", 20);
		ft_strlcat(pathname, number, 20);
		free(number);
		if (access(pathname, F_OK) == -1)
		{
			fd = open(pathname, O_CREAT | O_WRONLY | O_TRUNC, 0600);
			if (fd != -1)
			{
				read_until_limiter(STDIN_FILENO, fd, limiter);
				close(fd);
				return (ft_strdup(pathname));
			}
		}
		i++;
	}
	return (NULL);
}