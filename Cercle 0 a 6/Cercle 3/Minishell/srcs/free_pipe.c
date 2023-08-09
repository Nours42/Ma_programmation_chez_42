/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:25:12 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/09 12:12:52 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_and_clear_pipe(t_data *data)
{
	// free(data->pipe->pipe_fd);
	data->pipe->cmd_nbrs = 0;
	data->pipe->nbr_of_pipe = 0;
	data->pipe->idx = 0;
	close(data->pipe->infile);
	close(data->pipe->outfile);
	free(data->pipe);
}
