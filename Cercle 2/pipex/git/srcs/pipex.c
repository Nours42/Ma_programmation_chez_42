/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 06:12:20 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/12 12:44:09 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

static void	sub_dup2(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

void	args(t_data *d, char **argv)
{
	d->cmd_args = ft_qsplit(argv[2 + d->is_heredoc + d->idx]);
}

void	child(t_data d, char **argv, char **envp)
{
	d.pid = fork();
	if (!d.pid)
	{
		if (d.idx == 0)
			sub_dup2(d.infile, d.pipe[1]);
		else if (d.idx == d.cmd_nbrs - 1)
			sub_dup2(d.pipe[2 * d.idx - 2], d.outfile);
		else
			sub_dup2(d.pipe[2 * d.idx - 2], d.pipe[2 * d.idx + 1]);
		close_pipes(&d);
		args(&d, argv);
		d.cmd = get_cmd(d.cmd_paths, d.cmd_args[0]);
		if (!d.cmd)
			msg_pipe(d.cmd_args[0], &d);
		execve(d.cmd, d.cmd_args, envp);
	}
}
