/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:00:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/06/23 15:38:02 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_args(t_data *data)
{
	int	i;

	i = -1;
	while (data->cmd_args[++i])
		free(data->cmd_args[i]);
	free(data->cmd_args);
	ft_free_paths(data);
}

void	ft_free_paths(t_data *data)
{
	int	i;

	i = -1;
	while (data->cmd_paths[++i])
		free(data->cmd_paths[i]);
	free(data->cmd_paths);
}

void	ft_free_str_temp(int i, t_data *data)
{
	if (i == 1)
		free(data->str_temp);
	else if (i == 2)
		free(data->str_temp2);
	else if (i == 3)
	{
		free(data->str_temp);
		free(data->str_temp2);
	}

}

void	ft_free_all(t_data *data)
{
	ft_free_str_temp(3, data);
	ft_free_args(data);
	ft_free_paths(data);
	free(data);
}
