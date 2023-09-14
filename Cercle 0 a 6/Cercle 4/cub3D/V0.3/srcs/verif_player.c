/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:50:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/13 16:07:36 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_coordonate(t_data *data)
{
	int	i;
	int	j;

	i = 6;
	j = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] =='E' || data->map->map[i][j] =='N' || data->map->map[i][j] =='S'
				|| data->map->map[i][j] =='W')
			{
				data->map->coord[0] = i;
				data->map->coord[1] = j;
				break;
			}
			j++;
		}
		if (data->map->coord[0] > 0 && data->map->coord[1] > 0)
			break;
		i++;
	}
}

int	player_can_moove(t_data *data)
{
	if ((data->map->map[data->map->coord[0] - 1][data->map->coord[1]] == 49)
		&& (data->map->map[data->map->coord[0]][data->map->coord[1] - 1] == 49)
		&& (data->map->map[data->map->coord[0]][data->map->coord[1] + 1] == 49)
		&& (data->map->map[data->map->coord[0] + 1][data->map->coord[1]] == 49))
		return (1);
	return (0);
}

int	only_one_player(t_data *data)
{
	int i;
	int	j;
	int	player;

	i = data->map->coord[0];
	player = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] =='E' || data->map->map[i][j] =='N'
				|| data->map->map[i][j] =='S' || data->map->map[i][j] =='W')
				player++;
			j++;
		}
		i++;
	}
	if (player > 1)
		return (1);
	return (0);
}