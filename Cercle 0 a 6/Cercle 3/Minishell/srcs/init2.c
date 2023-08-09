/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:41:05 by nours42           #+#    #+#             */
/*   Updated: 2023/08/09 17:48:16 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_first(t_data *data, char **envp)
{
	int	i;

	i = -1;
	if (data->redirected == 3)
	{
		init_envp(data, envp);
		data->redirected = 0;
	}
	else
	{
		while(data->var->commands[++i])
			free(data->var->commands[i]);
		// i = -1;
		// while(data->args->cmd_args[++i])
		// 	free(data->args->cmd_args[i]);
		free_and_clear_args(data);
		free_and_clear_var(data);
		free_and_clear_pipe(data);
		free(data->original_prompt);
	}
	init_var(data);
	init_args(data);
	init_pipe(data);
	data->boucle = 0;
	data->cmd_prompt = NULL;
	data->end = 0;
	data->fd_redirect_out = 0;
	data->next_part = 42;
	data->original_prompt = NULL;
	data->pid_pipe = -1;
	data->pid_last = -1;
	data->redirected = 0;
}
