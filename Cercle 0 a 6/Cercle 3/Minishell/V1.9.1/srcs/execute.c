/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:07:40 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/01 16:29:19 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute_cmd(t_data *data, char **envp)
{
	if (find_builtin(data, envp) == 0)
	{
		data->cmd_prompt = get_cmd(data->args->cmd_paths, data->args->cmd_args[data->args_start]);
		if (data->args->cmd_args[data->args_start + 1])
		{
			if (ft_strncmp("<", data->args->cmd_args[data->args_start + 1], 1) == 0)
			{
				if (ft_strncmp("<<", data->args->cmd_args[data->args_start + 1], 2) == 0)
					return ;
				data->args->cmd_args[data->args_start + 1] = data->args->cmd_args[data->args_start];
				data->args->cmd_args = data->args->cmd_args + 1;
			}
		}
		if (data->cmd_prompt != NULL)
		{
			execve(data->cmd_prompt, data->args->cmd_args, envp);
			free(data->cmd_prompt);
		}
		else if (ft_strcmp(data->args->cmd_args[data->args_start + 1], "") == 0)
			exit(EXIT_FAILURE);
		else
		{
			ft_printf("%s : commande introuvable\n", data->args->cmd_args[data->args_start + 1]);
			free(data->args->cmd_args[data->args_start + 1]);
			exit(EXIT_FAILURE);
		}
		perror("Erreur d'exécution de la commande\n");
		exit(EXIT_FAILURE);
	}
}

void	exec_last(t_data *data, char **envp)
{
	pid_t pid;

	if (data->pipe->nbr_of_pipe > 0)
	{
		data->args_start = data->args_end[0] + 2;
		data->args_end[0] = data->args_max;
	}
	pid = fork();
	if (!pid)
	{
		check_redirect(data);
		if (find_builtin(data, envp) == 0)
			execute_cmd(data, envp);
	}
	else
	{
		dup2(data->pipe->outfile, STDOUT_FILENO);
		waitpid(pid, NULL, 0);
	}
}
