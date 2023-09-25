/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:40:05 by kaly              #+#    #+#             */
/*   Updated: 2023/09/25 17:08:53 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_first(t_data *data)
{
	data->i = 0;
	data->o = 0;
	if (data->orient > 0 && data->orient < 90)
	{
		data->first_x = data->delta_x * (data->player_x % PXL) / PXL;
		data->first_xa = sqrt((data->first_x * data->first_x) - ((data->player_x
						% PXL) * (data->player_x % PXL)));
		data->first_y = data->delta_y * (100 - (data->player_y % PXL)) / PXL;
		data->first_ya = sqrt((data->first_y * data->first_y)
				- ((100 - data->player_y % PXL)
					* (100 - data->player_y % PXL)));
		data->dist_x = data->first_x;
		data->dist_y = data->first_y;
		ft_check_wall_ne(data);
	}
	else if (data->orient > -90 && data->orient < 0)
	{
		data->first_x = data->delta_x * (100 - (data->player_x % PXL)) / PXL;
		data->first_xa = sqrt((data->first_x * data->first_x)
				- ((100 - data->player_x % PXL)
					* (100 - data->player_x % PXL)));
		data->first_y = data->delta_y * (100 - (data->player_y % PXL)) / PXL;
		data->first_ya = sqrt((data->first_y * data->first_y)
				- ((100 - data->player_y % PXL)
					* (100 - data->player_y % PXL)));
		data->dist_x = data->first_x;
		data->dist_y = data->first_y;
		ft_check_wall_se(data);
	}
	else if (data->orient < -90)
	{
		data->first_x = data->delta_x * (100 - (data->player_x % PXL)) / PXL;
		data->first_xa = sqrt((data->first_x * data->first_x)
				- ((100 - data->player_x % PXL)
					* (100 - data->player_x % PXL)));
		data->first_y = data->delta_y * (data->player_y % PXL) / PXL;
		data->first_ya = sqrt((data->first_y * data->first_y) - ((data->player_y
						% PXL) * (data->player_y % PXL)));
		data->dist_x = data->first_x;
		data->dist_y = data->first_y;
		ft_check_wall_sw(data);
	}
	else
	{
		data->first_x = data->delta_x * (data->player_x % PXL) / PXL;
		data->first_xa = sqrt((data->first_x * data->first_x) - ((data->player_x
						% PXL) * (data->player_x % PXL)));
		data->first_y = data->delta_y * (data->player_y % PXL) / PXL;
		data->first_ya = sqrt((data->first_y * data->first_y) - ((data->player_y
						% PXL) * (data->player_y % PXL)));
		data->dist_x = data->first_x;
		data->dist_y = data->first_y;
		ft_check_wall_nw(data);
	}
	data->rad_beta = cos(data->beta * (M_PI / 180.00));
	if (data->dist_x < data->dist_y)
		data->dist = data->dist_x * data->rad_beta;
	else
		data->dist = data->dist_y * data->rad_beta;
}

void	ft_init_delta(t_data *data)
{
	data->anglerad = data->orient * (M_PI / 180.00);
	if ((data->orient < 90 && data->orient > 0) || data->orient < -90)
	{
		data->xa = 100 / tan(data->anglerad);
		data->ya = 100 * tan(data->anglerad);
	}
	else
	{
		data->xa = 100 / tan(data->anglerad) * (-1);
		data->ya = 100 * tan(data->anglerad) * (-1);
	}
	data->delta_x = sqrt((data->xa * data->xa) + 100 * 100);
	data->delta_y = sqrt((data->ya * data->ya) + 100 * 100);
	ft_init_first(data);
}

void	ft_fill_floor(t_data *data)
{
	data->x = WINDOW_W;
	data->y = WINDOW_H;
	data->file = mlx_new_image(data->mlx_ptr, data->x, data->y);
	data->addr = mlx_get_data_addr(data->file, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->y = 0;
	while ((data->y) < WINDOW_H)
	{
		data->x = 0;
		while ((data->x) < WINDOW_W)
		{
			if (data->y < data->horizon)
				my_mlx_pixel(data, data->x, data->y, data->color_map_hex_C);
			else
				my_mlx_pixel(data, data->x, data->y, data->color_map_hex_F);
			data->x++;
		}
		data->y++;
	}
	calcul_distance(data);
	mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->file, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->file);
}
