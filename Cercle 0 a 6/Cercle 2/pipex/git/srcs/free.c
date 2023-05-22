/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 06:07:52 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/06 21:33:48 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	parent_free(t_data *data)
{
	int	i;

	i = 0;
	close(data->infile);
	close(data->outfile);
	if (data->is_heredoc)
		unlink(".heredoc_tmp");
	while (data->cmd_paths[i])
	{
		free(data->cmd_paths[i]);
		i++;
	}
	free(data->cmd_paths);
	free(data->pipe);
}

void	child_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmd_args[i])
	{
		free(data->cmd_args[i]);
		i++;
	}
	free(data->cmd_args);
	free(data->cmd);
}

void	pipe_free(t_data *data)
{
	close(data->infile);
	close(data->outfile);
	if (data->is_heredoc)
		unlink(".heredoc_tmp");
	free(data->pipe);
	msg_error("Error in split process in main.c");
	exit(1);
}
