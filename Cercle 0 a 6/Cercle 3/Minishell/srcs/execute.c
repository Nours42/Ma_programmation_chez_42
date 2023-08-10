/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:07:40 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/10 16:17:20 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_cmp_paths(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (i);
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	if (ft_strlen(cmd) == 0)
		return (NULL);
	if (cmd)
	{
		while (*paths)
		{
			if (ft_cmp_paths(cmd, *paths) >= 4)
				return (cmd);
			tmp = ft_strjoin(*paths, "/");
			command = ft_strjoin(tmp, cmd);
			free(tmp);
			if (access(command, 0) == 0)
				return (command);
			free(command);
			paths++;
		}
	}
	return (NULL);
}

void	execute_cmd(t_data *d, char **envp)
{
	d->cmd_prompt = get_cmd(d->args->cmd_paths,
			d->args->cmd_args[d->args_start]);
	if (d->args->cmd_args[d->args_start + 1])
	{
		if (ft_strncmp("<", d->args->cmd_args[d->args_start + 1], 1) == 0)
		{
			if (ft_strncmp("<<", d->args->cmd_args[d->args_start + 1], 2)
				== 0)
				return ;
			d->args->cmd_args[d->args_start + 1]
				= d->args->cmd_args[d->args_start];
			d->args->cmd_args = d->args->cmd_args + 1;
		}
	}
	if (d->cmd_prompt != NULL)
		execve(d->cmd_prompt, d->args->cmd_args, envp);
	else
	{
		ft_printf("%s : commande introuvable\n",
			d->args->cmd_args[d->args_start]);
		exit(EXIT_FAILURE);
	}
}

void	exec_last(t_data *d, char **envp)
{
	if (d->pid_pipe > 0)
	{
		kill(d->pid_pipe, SIGKILL);
		d->pid_pipe = 0;
	}
	if (d->pipe->nbr_of_pipe > 0)
	{
		d->args_start = d->args_end[0] + 2;
		d->args_end[0] = d->args_max;
	}
	if ((ft_strcmp("", d->original_prompt) == 0) || ft_only_space(d->original_prompt) == 1)
		shell_loop(d, envp);
	else
	{
		d->end = 1;
		check_exit(d);
		if (find_builtin_outside(d))
			return ;
		d->pid_last = fork();
		if (d->pid_last == -1)
			msg_error("fork exec_last doesn,t work.\n");
		else if (d->pid_last == 0)
		{
			check_redirect(d);
			find_builtin_inside(d);
			execute_cmd(d, envp);
		}
		else
		{
			dup2(d->pipe->outfile, STDOUT_FILENO);
			waitpid(d->pid_last, &d->error_number, 0);
			d->error_number *= 127;
		}
	}
}
