/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:07:40 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/08 14:38:28 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	else if (ft_strcmp(d->args->cmd_args[d->args_start + 1], "") == 0)
		exit(EXIT_FAILURE);
	else
	{
		ft_printf("%s : commande introuvable\n",
			d->args->cmd_args[d->args_start + 1]);
		free(d->args->cmd_args[d->args_start + 1]);
		exit(EXIT_FAILURE);
	}
	perror("Erreur d'exécution de la commande\n");
	exit(EXIT_FAILURE);
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
	if (ft_strcmp("", d->original_prompt) == 0)
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
			waitpid(d->pid_last, NULL, 0);
			if (d->kill_process == 1)
				exit(EXIT_FAILURE);
		}
	}
}
