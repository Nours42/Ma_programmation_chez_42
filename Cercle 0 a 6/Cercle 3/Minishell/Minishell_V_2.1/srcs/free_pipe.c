/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <kaly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:25:12 by sdestann          #+#    #+#             */
/*   Updated: 2023/08/02 12:13:37 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_and_clear_pipe(t_data *data)
{
	int	i;

	i = -1;
	while (data->pipe->pipe[++i])
		data->pipe->pipe[i] = 0;
	i = -1;
	data->pipe->cmd_nbrs = 0;
	data->pipe->nbr_of_pipe = 0;
	data->pipe->idx = 0;
	close(data->pipe->infile);
	close(data->pipe->outfile);
	free(data->pipe);
}