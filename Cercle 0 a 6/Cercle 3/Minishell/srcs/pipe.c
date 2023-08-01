/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:58:10 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/01 18:51:26 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	how_many_pipe(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (data->args->cmd_args[++i])
	{
		if (ft_strcmp("|", data->args->cmd_args[i]) == 0)
		{
			data->args_end[j++] = i - 1;
			data->pipe->nbr_of_pipe++;
		}
	}
	data->args_end[j] = i - 1;
	data->args_max = data->args_end[j];
	// ft_printf("args end end %d : %d\n", j, data->args_end[j]);
	if (data->pipe->nbr_of_pipe > 0)
		data->pipe->pipe = (int *)malloc(sizeof(int) * data->pipe->nbr_of_pipe);
}

void	execute_pipes(t_data *data, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	if (!pid)
	{
		check_redirect(data);
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute_cmd(data, envp);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

// void	redirect_out(t_data *data)
// {
// 	if (!file_out || !type_out)
// 		return ;
// 	while (data->file_out[i])
// 	{
// 		if (ft_strcmp(">>", data->args->cmd_args[i]) == 0)
// 		{
// 			redirect_dobble_right(data, envp, i);
// 			fd_in open(file[i], O_READONLY);
// 			dup2(fd_in, STDIN_FILENO);
// 		}
// 		else if (ft_strcmp(">", data->args->cmd_args[i]) == 0)
// 			{
// 			redirect_simple_right(data, envp, i);
// 			fd_in = ft_heredoc(file_in[i])
// 			dup2(fd_in, STDIN_FILENO);
// 		}
// 		i++;
// 	}
// }
// //redirect verifie s'il y a une entree ou sortie et de quoi elle est compose
// //apres l'open du redirect je fais mon dup2 

// void	redirect_in(t_data *data)
// {
// 	if (!file_in || !type_in)
// 		return ;
// 	while (data->file_in[i])
// 	{
// 		if (ft_strcmp("<", data->args->cmd_args[i]) == 0)
// 		{
// 			redirect_simple_left(data, envp, i);
// 			fd_in open(file[i], O_READONLY);
// 			dup2(fd_in, STDIN_FILENO);
// 		}
// 		else if (ft_strcmp("<<", data->args->cmd_args[i]) == 0)
// 		{
// 			redirect_dobble_left(data, envp, i);
// 			fd_in = ft_heredoc(file_in[i])
// 			dup2(fd_in, STDIN_FILENO);
// 		}
// 		i++;
// 	}
// }

// int ft_heredoc(char *str)
// {
// 	char *line;
// 	int	fd[2];

// 	if(pipe(fd) ==-1)
// 		return (-1);
// 	while (1)
// 	{
// 		line = readline("> ");
// 		if (!line)
// 			return (-1);
// 		if (compare le read avec le heredoc de sortie)
// 			break;
// 		ft_printf de la chose tapee
// 		free(line)
// 	}
// 	free(line si existe)
// 	close(fd[1])
// 	return (fd[0]);
// }

void	sub_dup2(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

void	close_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data->pipe->nbr_of_pipe))
	{
		close(data->pipe->pipe_idx[i]);
		i++;
	}
}

// void	child(t_data *d, char **envp)
// {
// 	if (!envp)
// 		return ;
// 	d->pid = fork();
// 	if (!d->pid)
// 	{
// 		if (d->pipe->idx == 0)
// 			sub_dup2(d->pipe->infile, d->pipe->pipe[0]);
// 		// else if (d->pipe->idx == d->pipe->cmd_nbrs - 1)
// 		// 	sub_dup2(d->pipe->pipe[2 * d->pipe->idx - 2], d->pipe->outfile);
// 		// else
// 		// 	sub_dup2(d->pipe->pipe[2 * d->pipe->idx - 2], 
			// d->pipe->pipe[2 * d->pipe->idx + 1]);
// 		// close_pipes(d);
// 		// d->pipe->cmd = get_cmd(d->args->cmd_paths, d->args->cmd_args[0]);
// 		// if (!d->pipe->cmd)
// 		// 	msg_pipe(d->args->cmd_args[0], d);
// 		// execve(d->pipe->cmd, d->args->cmd_args, envp);
// 	}
// 	ft_printf("%s\n", d->args->cmd_args[0]);
// }

void	msg_pipe(char *arg, t_data *data)
{
	write(2, "Command not found: ", 20);
	write(2, arg, ft_strlen(arg));
	write(2, "\n", 1);
	child_free(data);
	exit(127);
}
