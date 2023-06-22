/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:05:07 by sdestann          #+#    #+#             */
/*   Updated: 2023/06/22 10:50:28 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}

void	ft_free(t_data *data)
{
	int	i;

	i = -1;
	while (data->cmd_args[++i])
		free(data->cmd_args[i]);
	free(data->cmd_args);
	i = -1;
	while (data->cmd_paths[++i])
		free(data->cmd_paths[i]);
	free(data->cmd_paths);
	free(data->str_temp);
	free(data);
}

void	ft_free2(t_data *data)
{
	int	i;

	i = -1;
	while (data->cmd_paths[++i])
		free(data->cmd_paths[i]);
	free(data->cmd_paths);
	free(data);
}
