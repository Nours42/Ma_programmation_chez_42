/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:40:05 by kaly              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/09/26 15:25:56 by sdestann         ###   ########.fr       */
=======
/*   Updated: 2023/09/26 10:09:03 by sdestann         ###   ########.fr       */
>>>>>>> e5518b7c21a263b6eca4816ebf231b237429214e
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../objects/textures/down640.ppm"

void	my_mlx_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	calcul_distance(t_data *data)
{
	data->beta = 30.00;
	data->orient = data->player_orient + data->beta;
	data->x = 0;
	while (data->x < WINDOW_W)
	{
		if (data->orient >= 180)
			data->orient -= 360.00;
		if (data->orient <= -180)
			data->orient += 360.00;
		ft_init_delta(data);
		data->y = data->horizon - (100 / data->dist * 900);
		while ((data->y) < data->horizon + (100 / data->dist * 900))
		{
			if (data->y >= 0 && data->y < WINDOW_H)
				my_mlx_pixel(data, data->x, data->y, 0xFF0000);
			data->y++;
		}
		data->x++;
		data->beta -= 0.03125;
		data->orient -= 0.03125;
	}
	return ;
}

int	render(t_data *data)
{
	if (data->win_ptr != NULL)
	{
		if (data->exit == 0)
		{
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			data->win_ptr = NULL;
		}
	}
	return (0);
}

void	ft_create_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_W,
			WINDOW_H, "Zelda");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return ;
	}
	mlx_hook(data->win_ptr, 2, 1L << 0, &handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 1L << 0, &ft_quit, data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	data->player_orient = 55.01;
	ft_fill_floor(data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
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
				my_mlx_pixel(data, data->x, data->y, data->color_map_hex_c);
			else
				my_mlx_pixel(data, data->x, data->y, data->color_map_hex_f);
			data->x++;
		}
		data->y++;
	}
	calcul_distance(data);
	mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->file, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->file);
}
