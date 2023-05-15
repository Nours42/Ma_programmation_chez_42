/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:31:27 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/06 21:40:16 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// to write, read, close, access, pipe, dup, dup 2, execve ans fork

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

// malloc, free et exit

# include <stdlib.h>

// to open and unlink

# include <fcntl.h>

// to waitpid and wait

# include <sys/wait.h>

// to strerror

# include <string.h>

// to perror

# include <stdio.h>

// to libft, get_next_line, ft_printf etc...

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

typedef struct s_data
{
	int		infile;
	int		outfile;
	char	*env_paths;
	char	**cmd_paths;
	char	*cmd;
	char	**cmd_args;
	int		is_heredoc;
	pid_t	pid;
	int		cmd_nbrs;
	int		pipe_nbrs;
	int		*pipe;
	int		idx;
}				t_data;

// error.c

void	msg_pipe(char *arg, t_data *data);
void	msg_error(char *err);
int		some_error(char *str);

// free.c

void	parent_free(t_data *data);
void	child_free(t_data *data);
void	pipe_free(t_data *data);

// here_doc.c

//static int	find_nl(char *str);
//static char	*get_line(char *str);
//static char	*trim_rem(char *str);
//static int	get_next_line(int fd, char **line);
void	here_doc(char *argv, t_data *data);

// main.c

//static int	args_in(char *arg, t_data *data);
//static void	get_infile(char **argv, t_data *data);
//static void	get_outfile(char *argv, t_data *data);
//static void	open_files(int *argc, char **argv, char **envp, t_data *data);
int		main(int argc, char **argv, char **envp);

// pipes.c

void	creat_pipes(t_data *data);
void	close_pipes(t_data *data);

//pipex.c

char	*find_path(char **envp);
//static char	*get_cmd(char **paths, char *cmd);
//static void	sub_dup2(int zero, int first);
void	child(t_data d, char **argv, char **envp);

#endif