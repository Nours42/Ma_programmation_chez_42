/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:33:20 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/06 21:33:54 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	creat_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->cmd_nbrs - 1)
	{
		if (pipe(data->pipe + 2 * i) < 0)
			parent_free(data);
		i++;
	}
}

void	close_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data->pipe_nbrs))
	{
		close(data->pipe[i]);
		i++;
	}
}
