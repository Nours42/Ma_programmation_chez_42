/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <kaly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:07:40 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/02 15:46:34 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute_cmd(t_data *d, char **envp)
{
	if (find_builtin(d, envp) == 0)
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
		{
			execve(d->cmd_prompt, d->args->cmd_args, envp);
			free(d->cmd_prompt);
		}
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
}

void	exec_last(t_data *d, char **envp)
{
	if (d->pipe->nbr_of_pipe > 0)
	{
		d->args_start = d->args_end[0] + 2;
		d->args_end[0] = d->args_max;
	}
	if (ft_strcmp("", d->original_prompt) == 0)
		shell_loop(d, envp);
	if (ft_strcmp("exit", d->original_prompt) == 0)
		ft_exit(d);
	else if (ft_strcmp("export", d->args->cmd_args[d->args_start]) == 0)
		ft_export(d, d->args->cmd_args[d->args_start + 1]);
	else if (ft_strcmp("unset", d->args->cmd_args[d->args_start]) == 0)
		ft_unset(d, d->args->cmd_args[d->args_start + 1]);
	else
	{
		d->end = 1;
		check_redirect(d);
		if (find_builtin2(d) == 0)
		{
			d->pid_last = fork();
			if (d->pid_last == -1)
				return ;
			else if (d->pid_last == 0)
				execute_cmd(d, envp);
			else
			{
				dup2(d->pipe->outfile, STDOUT_FILENO);
				waitpid(d->pid_last, NULL, 0);
			}
		}
	}
}
