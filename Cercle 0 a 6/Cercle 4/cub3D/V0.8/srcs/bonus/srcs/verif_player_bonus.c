/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_player_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:50:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/26 12:12:14 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	player_coordonate(t_data *data, int i, int j)
{
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E' || data->map[i][j] == 'N'
				|| data->map[i][j] == 'S' || data->map[i][j] == 'W')
			{
				data->player_x = i * PXL + 50;
				data->player_y = j * PXL + 50;
				if (data->map[i][j] == 'E')
					data->player_orient = 0.01;
				else if (data->map[i][j] == 'N')
					data->player_orient = 90.01;
				else if (data->map[i][j] == 'W')
					data->player_orient = 180.01;
				else
					data->player_orient = -90.01;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	only_one_player(t_data *data)
{
	int	i;
	int	j;
	int	player;

	i = data->map_first_line;
	player = 0;
	while (data->map[i])
	{
		j = 0;
		while (i < data->map_last_line && data->map[i][j])
		{
			if (data->map[i][j] == 'E' || data->map[i][j] == 'N'
				|| data->map[i][j] == 'S' || data->map[i][j] == 'W')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (1);
	return (0);
}
