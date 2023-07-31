/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:07:40 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/31 15:22:51 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute_command(t_data *data, char **envp)
{
	data->pid = fork();
	if (data->pid == 0)
	{
		data->cmd_prompt = get_cmd(data->args->cmd_paths,
				data->args->cmd_args[data->args_start]);
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
	else if (data->pid < 0)
		perror("Erreur lors de la création du processus\n");
	else
		wait(NULL);
}
