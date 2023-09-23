/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:50:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/23 19:07:47 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_coordonate(t_data *data)
{
	int	i;
	int	j;

	i = data->Map_first_line;
	while (data->map[i])
	{
		// j = (int)ft_strlen(data->map[i]);
		// ft_printf("ligne : %d size / size_max: %d / %d\n", i, j, data->size_max);
		j = 0;
		// print_map(data, data->Map_first_line - 1);
		if(data->map[i] && data->map[j])
		{
			while (data->map[i][j])
			{
				if (data->map[i][j] == 'E' || data->map[i][j] == 'N'
					|| data->map[i][j] == 'S' || data->map[i][j] == 'W')
				{
					data->player_x = i * 100 + 50;
					data->player_y = j * 100 + 50;
					if (data->map[i][j] == 'E')
						data->player_orient = 0;
					else if (data->map[i][j] == 'N')
						data->player_orient = 90;
					else if (data->map[i][j] == 'W')
						data->player_orient = 180;
					else
						data->player_orient = 270;
					return ;
				}
				j++;
			}
		}
		i++;
	}
}

int	only_one_player(t_data *data)
{
	int	i;
	int	j;
	int	player;

	i = data->Map_first_line;
	player = 0;
	while (data->map[i])
	{
		j = 0;
		while (i < data->Map_last_line && data->map[i][j])
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
