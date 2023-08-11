/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:41:05 by nours42           #+#    #+#             */
/*   Updated: 2023/08/11 11:54:33 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_first(t_data *data, char **envp)
{
	if (data->redirected == 3)
	{
		init_envp(data, envp);
		data->redirected = 0;
	}
	else
	{
		if (data->var->commands[0])
			free(data->var->commands[0]);
		free_and_clear_args(data);
		free_and_clear_var(data);
		free_and_clear_pipe(data);
		free(data->original_prompt);
		free(data->cmd_prompt);
	}
	init_var(data);
	init_args(data);
	init_pipe(data);
	init_first_2(data);
}

void	init_first_2(t_data *data)
{
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
