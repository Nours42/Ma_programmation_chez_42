/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:07:40 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/01 18:18:39 by sdestann         ###   ########.fr       */
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
	pid_t	pid;

	if (d->pipe->nbr_of_pipe > 0)
	{
		d->args_start = d->args_end[0] + 2;
		d->args_end[0] = d->args_max;
	}
	d->end = 1;
	pid = fork();
	if (!pid)
	{
		check_redirect(d);
		if (find_builtin(d, envp) == 0)
			execute_cmd(d, envp);
	}
	else
	{
		dup2(d->pipe->outfile, STDOUT_FILENO);
		waitpid(pid, NULL, 0);
	}
}
