/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:25:12 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/01 18:19:34 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	parent_free(t_data *data)
{
	int	i;

	i = 0;
	close(data->pipe->infile);
	while (data->args->cmd_paths[i])
	{
		free(data->args->cmd_paths[i]);
		i++;
	}
	free(data->args->cmd_paths);
	free(data->pipe->pipe_idx);
}

void	child_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->args->cmd_args[i])
	{
		free(data->args->cmd_args[i]);
		i++;
	}
	free(data->args->cmd_args);
}

void	pipe_free(t_data *data)
{
	if (!data)
		return ;
	close(data->pipe->infile);
	free(data->pipe->pipe_idx);
	msg_error("Error in split process in main.c");
	exit(1);
}
