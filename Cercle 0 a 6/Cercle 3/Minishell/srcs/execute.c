/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:07:40 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/05 13:22:06 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute_command(t_data *data, char **envp)
{
	// 1 - Verifier le niveau de data->lvl
	// 2 - Remplacer les $xxx en recherchant dans l'env les exports
	// 3 - Executer les commandes du lvl le plus haut, puis -- etc
	data->pid = fork();
	//ft_printf("exec command\n");
	if (data->pid == 0)
	{
		data->str_temp2 = get_cmd(data->cmd_paths, data->cmd_args[0]);
		if (data->str_temp2 != NULL)
			execve(data->str_temp2, data->cmd_args, envp);
		else
		{
			ft_printf("%s : commande introuvable\n", data->cmd_args[0]);
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
