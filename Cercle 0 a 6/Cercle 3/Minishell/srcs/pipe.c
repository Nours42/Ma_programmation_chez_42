/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:58:10 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/27 18:40:23 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	how_many_pipe(t_data *data)
{
	int	i;

	i = -1;
	while (data->args->cmd_args[++i])
		if (ft_strcmp("|", data->args->cmd_args[i]) == 0)
			data->pipe->nbr_of_pipe++;
}

void	creat_pipes(t_data *data)
{
	int	i;

	i = 0;
	if (data->pipe->nbr_of_pipe > 0)
	{
		while (i < data->pipe->nbr_of_pipe)
		{
			if (pipe(data->pipe->pipe + 2 * i) < 0)
				parent_free(data);
			i++;
		}
	}
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

void	sub_dup2(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

void	child(t_data *d, char **envp)
{
	if (!envp)
		return ;
	d->pid = fork();
	if (!d->pid)
	{
		if (d->pipe->idx == 0)
			sub_dup2(d->pipe->infile, d->pipe->pipe[0]);
		else if (d->pipe->idx == d->pipe->cmd_nbrs - 1)
			sub_dup2(d->pipe->pipe[2 * d->pipe->idx - 2], d->pipe->outfile);
		else
			sub_dup2(d->pipe->pipe[2 * d->pipe->idx - 2], d->pipe->pipe[2 * d->pipe->idx + 1]);
		close_pipes(d);
		d->pipe->cmd = get_cmd(d->args->cmd_paths, d->args->cmd_args[0]);
		if (!d->pipe->cmd)
			msg_pipe(d->args->cmd_args[0], d);
		execve(d->pipe->cmd, d->args->cmd_args, envp);
	}
	ft_printf("%s\n", d->args->cmd_args[0]);
}

void	msg_pipe(char *arg, t_data *data)
{
	write(2, "Command not found: ", 20);
	write(2, arg, ft_strlen(arg));
	write(2, "\n", 1);
	child_free(data);
	exit(127);
}