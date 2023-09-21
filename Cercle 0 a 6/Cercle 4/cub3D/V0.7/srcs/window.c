/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:40:05 by kaly              #+#    #+#             */
/*   Updated: 2023/09/21 16:35:30 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
		ft_quit(data);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	calcul_distance(t_data *data)
{
	int	index_x;
	int	i;
	int	x;

	i = 0;
	x = 0;
	index_x = 0;
	while ((data->player_x - i) % 100 != 0)
		i++;
	index_x = ((data->player_x - i) / 100) - 1;
	while ((data->player_y - x) % 100 != 0)
		x++;
	while (1)
	{
		if (data->map[index_x][data->player_y / 100] == '1')
		{
			affiche_un_mur(data, i);
			return (i);
		}
		index_x--;
		i += 100;
	}
	return (i);
}

void	affiche_un_mur(t_data *data, int i)
{
	data->x = WINDOW_W / 2 - 300;
	while ((data->x) < WINDOW_W / 2 + 300)
	{
		data->y = WINDOW_H / 2 - (200 / (i / 100));
		while ((data->y) < WINDOW_H / 2 + (200 / (i / 100)))
		{
			my_mlx_pixel_put(data, data->x, data->y, 0xFF0000);
			data->y++;
		}
		data->x++;
	}
}

void	ft_fill_floor(t_data *data)
{
	data->file = mlx_new_image(data->mlx_ptr, data->x, data->y);
	data->addr = mlx_get_data_addr(data->file, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->y = 0;
	while ((data->y) < WINDOW_H)
	{
		data->x = 0;
		while ((data->x) < WINDOW_W)
		{
			if (data->y < WINDOW_H / 2)
				my_mlx_pixel_put(data, data->x, data->y, data->color_map_hex_C);
			else
				my_mlx_pixel_put(data, data->x, data->y, data->color_map_hex_F);
			data->x++;
		}
		data->y++;
	}
	calcul_distance(data);
	mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->file, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->file);
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
	ft_fill_floor(data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
}
