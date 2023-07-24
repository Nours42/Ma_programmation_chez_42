/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:25:12 by sdestann          #+#    #+#             */
/*   Updated: 2023/07/25 00:38:10 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	parent_free(t_data *data)
{
	int	i;

	i = 0;
	close(data->pipe->infile);
	close(data->pipe->outfile);
	while (data->args->cmd_paths[i])
	{
		free(data->args->cmd_paths[i]);
		i++;
	}
	free(data->args->cmd_paths);
	free(data->pipe->pipe);
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
	free(data->pipe->cmd);
}

void	pipe_free(t_data *data)
{
	close(data->pipe->infile);
	close(data->pipe->outfile);
	free(data->pipe->pipe);
	msg_error("Error in split process in main.c");
	exit(1);
}
