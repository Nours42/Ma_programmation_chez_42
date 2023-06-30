/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <kaly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:00:42 by sdestann          #+#    #+#             */
/*   Updated: 2023/06/28 11:05:13 by kaly             ###   ########.fr       */
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

void	ft_free_all(int i, t_data *data)
{
	ft_free_str_temp(i, data);
	ft_free_args(data);
	ft_free_paths(data);
	free(data);
}

