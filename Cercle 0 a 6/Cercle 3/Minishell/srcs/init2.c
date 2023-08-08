/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:41:05 by nours42           #+#    #+#             */
/*   Updated: 2023/08/07 17:38:33 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_first(t_data *data, char **envp)
{
	if (!data->envp)
		init_envp(data, envp);
	if (data->args)
		free_and_clear_args(data);
	if (data->pipe && data->pipe->nbr_of_pipe != 0)
		free_and_clear_pipe(data);
	init_var(data);
	init_args(data);
	init_pipe(data);
	data->boucle = 0;
	data->cmd_prompt = NULL;
	data->end = 0;
	data->fd_redirect_out = 0;
	data->kill_process = 0;
	data->next_part = 42;
	data->original_prompt = NULL;
	data->pid_pipe = -1;
	data->pid_last = -1;
	data->redirected = 0;
}
