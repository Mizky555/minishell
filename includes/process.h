/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:17:20 by tliangso          #+#    #+#             */
/*   Updated: 2023/07/16 23:17:39 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# define IO_READ 1
# define IO_HEREDOC 2
# define IO_TRUNC 3
# define IO_APPEND 4

typedef struct s_io
{
	int		type;
	char	*filename;
	char	*limiter;
	int		fd;
}	t_io;

typedef struct s_process
{
	int		pid;
	int		status;
	int		fileio[2];
	int		*parent;
	int		*child;
	int		**pipes;
	int		argc;
	char	**argv;
	char	**envp;
	char	*path;
	int		run;
	t_io	**io;
}	t_process;

void		error_print(char *message);
void		error_print2(char *message1, char *message2);
void		error_exit_pipex(void);
void		mini_end_exit(void *arg, t_process *proc);

char		*get_pathname(char *cmd, char **envp);

char		*read_here_doc(char *limiter);

int			nta_size(void **array);
void		nta_free(void **array);
void		**nta_new(void *p);
void		**nta_add_back(void **array, void *p);
void		**nta_add_front(void **array, void *p);

void		*free_pipes(int **pipes);
int			**close_pipes(int **pipes);
int			**make_pipes(int n);

t_io		**add_file(t_io **ios, char *filename, int type, char *limiter);
int			open_files(t_io **ios, int type);
void		close_files(t_io **ios);
void		free_files(t_io **ios);

t_process	**add_proc(t_process **procs, char **argv, char **envp);
void		free_procs(t_process **proc);

void		*free_pipex(t_process **procs);
int			init_pipex(t_process **procs);
void		set_file_io(t_process *proc);

#endif