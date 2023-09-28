/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_check_wall_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:40:05 by kaly              #+#    #+#             */
/*   Updated: 2023/09/26 12:12:02 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_check_wall_sw(t_data *data)
{
	data->i = 0;
	data->o = 0;
	while (1)
	{
		if (data->dist_x <= data->dist_y)
		{
			data->check_y = (data->player_y - (int)(data->first_xa
						+ data->xa * data->i + 1.00)) / PXL;
			data->check_x = (data->player_x / PXL) + (1 + data->i);
			if (data->map[data->check_x][data->check_y] == '1')
				break ;
			data->dist_x += data->delta_x;
			data->i++;
		}
		else
		{
			data->check_x = (data->player_x + (int)(data->first_ya
						+ data->ya * data->o)) / PXL;
			data->check_y = (data->player_y / PXL) - (1 + data->o);
			if (data->map[data->check_x][data->check_y] == '1')
				break ;
			data->dist_y += data->delta_y;
			data->o++;
		}
	}
}

void	ft_check_wall_se(t_data *data)
{
	data->i = 0;
	data->o = 0;
	while (1)
	{
		if (data->dist_x <= data->dist_y)
		{
			data->check_y = (data->player_y + (int)(data->first_xa
						+ data->xa * data->i)) / PXL;
			data->check_x = (data->player_x / PXL) + (1 + data->i);
			if (data->map[data->check_x][(int)data->check_y] == '1')
				break ;
			data->dist_x += data->delta_x;
			data->i++;
		}
		else
		{
			data->check_x = (data->player_x + (int)(data->first_ya
						+ data->ya * data->o)) / PXL;
			data->check_y = (data->player_y / PXL) + (1 + data->o);
			if (data->map[data->check_x][data->check_y] == '1')
				break ;
			data->dist_y += data->delta_y;
			data->o++;
		}
	}
}

void	ft_check_wall_nw(t_data *data)
{
	data->i = 0;
	data->o = 0;
	while (1)
	{
		if (data->dist_x <= data->dist_y)
		{
			data->check_y = (data->player_y - (int)(data->first_xa
						+ data->xa * data->i + 1.00)) / PXL;
			data->check_x = (data->player_x / PXL) - (1 + data->i);
			if (data->map[data->check_x][(int)data->check_y] == '1')
				break ;
			data->dist_x += data->delta_x;
			data->i++;
		}
		else
		{
			data->check_x = (data->player_x - (int)(data->first_ya
						+ data->ya * data->o + 1.00)) / PXL;
			data->check_y = (data->player_y / PXL) - (1 + data->o);
			if (data->map[data->check_x][data->check_y] == '1')
				break ;
			data->dist_y += data->delta_y;
			data->o++;
		}
	}
}

void	ft_check_wall_ne(t_data *data)
{
	while (1)
	{
		if (data->dist_x <= data->dist_y)
		{
			data->check_y = (data->player_y + (int)(data->first_xa
						+ data->xa * data->i)) / PXL;
			data->check_x = (data->player_x / PXL) - (1 + data->i);
			if (data->map[data->check_x][(int)data->check_y] == '1')
				break ;
			data->dist_x += data->delta_x;
			data->i++;
		}
		else
		{
			data->check_x = (data->player_x - (int)(data->first_ya
						+ (data->ya * data->o) + 1.00)) / PXL;
			data->check_y = (data->player_y / PXL) + (1 + data->o);
			if (data->map[data->check_x][data->check_y] == '1')
				break ;
			data->dist_y += data->delta_y;
			data->o++;
		}
	}
}
