/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:50:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/11 12:25:03 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_coordonate(t_map	*cub)
{
	int	i;
	int	j;

	i = 6;
	j = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'E' || cub->map[i][j] == 'N'
				|| cub->map[i][j] == 'S' || cub->map[i][j] == 'W')
			{
				cub->coord[0] = i;
				cub->coord[1] = j;
				break ;
			}
			j++;
		}
		if (cub->coord[0] > 0 && cub->coord[1] > 0)
			break ;
		i++;
	}
}

int	player_can_moove(t_map	*cub)
{
	if ((cub->map[cub->coord[0] - 1][cub->coord[1]] == 49)
		&& (cub->map[cub->coord[0]][cub->coord[1] - 1] == 49)
		&& (cub->map[cub->coord[0]][cub->coord[1] + 1] == 49)
		&& (cub->map[cub->coord[0] + 1][cub->coord[1]] == 49))
		return (1);
	return (0);
}

int	only_one_player(t_map *cub)
{
	int	i;
	int	j;
	int	player;

	i = cub->coord[0];
	player = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'E' || cub->map[i][j] == 'N'
				|| cub->map[i][j] == 'S' || cub->map[i][j] == 'W')
				player++;
			j++;
		}
		i++;
	}
	if (player > 1)
		return (1);
	return (0);
}
