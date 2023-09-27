/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:40:05 by kaly              #+#    #+#             */
/*   Updated: 2023/09/27 09:01:10 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int		pix_text(t_data *data , char *addr, int line_lenght, int bpp)
{
	int color;

	color = *(unsigned int*)(addr + (data->pixel_y * line_lenght + (data->pixel_x / 2) * (bpp / 8)));
	return (color);
}

void	calcul_distance(t_data *data)
{
	int	i;

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
		data->y = data->horizon - (100 / data->dist * 1000);
		i = -1;
		while ((data->y) < data->horizon + (100 / data->dist * 1000))
		{
			if (data->y >= 0 && data->y < WINDOW_H)
			{
				if (++i == 0)
					data->origin_y = data->y;
				data->draw_y = data->y - data->origin_y;
				data->pixel_y = data->draw_y * data->wall_n_height / ((data->horizon - data->origin_y) * 2) + 1;
				if (data->dist_x <= data->dist_y)
				{
					if ((data->orient > 0 && data->orient < 90) || (data->orient > -90 && data->orient < 0))
						data->pixel_x = (data->player_y + (int)(data->first_xa + data->xa * data->i)) % PXL;
					else
						data->pixel_x = (data->player_y - (int)(data->first_xa + data->xa * data->i + 1.00)) % PXL;
				}
				else
				{
					if (data->orient > 0)
						data->pixel_x = (data->player_x - (int)(data->first_ya + data->ya * data->o + 1.00)) % PXL;
					else
						data->pixel_x = (data->player_x + (int)(data->first_ya + data->ya * data->o)) % PXL;
				}
				calcul_distance_part_two(data);
			}
			data->y++;
		}
		data->x++;
		data->beta -= 0.03125;
		data->orient -= 0.03125;
	}
	return ;
}

void	calcul_distance_part_two(t_data *data)
{
	if (((data->orient > 0 && data->orient < 90) && data->dist_x < data->dist_y) || (data->orient > 90 && data->dist_x < data->dist_y))
		my_mlx_pixel(data, data->x, data->y, pix_text(data, data->wall_n_addr, data->wall_n_line_length, data->wall_n_bpp));
	else if (((data->orient < 0 && data->orient > -90) && data->dist_x < data->dist_y) || (data->orient < -90 && data->dist_x < data->dist_y))
		my_mlx_pixel(data, data->x, data->y, pix_text(data, data->wall_s_addr, data->wall_s_line_length, data->wall_s_bpp));
	else if (((data->orient > 0 && data->orient < 90) && data->dist_x > data->dist_y) || ((data->orient < 0 && data->orient > -90) && data->dist_x > data->dist_y))
		my_mlx_pixel(data, data->x, data->y, pix_text(data, data->wall_e_addr, data->wall_e_line_length, data->wall_e_bpp));
	else
		my_mlx_pixel(data, data->x, data->y, pix_text(data, data->wall_w_addr, data->wall_w_line_length, data->wall_w_bpp));
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

void	ft_init_wall_img(t_data *data)
{
	data->wall_n = mlx_xpm_file_to_image(data->mlx_ptr, "./img/down.xpm",
			&data->wall_n_width, &data->wall_n_height);
	data->wall_n_addr = mlx_get_data_addr(data->wall_n, &data->wall_n_bpp,
			&data->wall_n_line_length, &data->wall_n_endian);
	data->wall_e = mlx_xpm_file_to_image(data->mlx_ptr, "./img/black_window.xpm",
			&data->wall_e_width, &data->wall_e_height);
	data->wall_e_addr = mlx_get_data_addr(data->wall_e, &data->wall_e_bpp,
			&data->wall_e_line_length, &data->wall_e_endian);
	data->wall_s = mlx_xpm_file_to_image(data->mlx_ptr, "./img/red_window.xpm",
			&data->wall_s_width, &data->wall_s_height);
	data->wall_s_addr = mlx_get_data_addr(data->wall_s, &data->wall_s_bpp,
			&data->wall_s_line_length, &data->wall_s_endian);
	data->wall_w = mlx_xpm_file_to_image(data->mlx_ptr, "./img/window.xpm",
			&data->wall_w_width, &data->wall_w_height);
	data->wall_w_addr = mlx_get_data_addr(data->wall_w, &data->wall_w_bpp,
			&data->wall_w_line_length, &data->wall_w_endian);
	return ;
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
	ft_init_wall_img(data);
	mlx_hook(data->win_ptr, 2, 0, &handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 1L << 0, &ft_quit, data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	data->player_orient = 90.01;
	ft_fill_floor(data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
}

void	ft_fill_floor(t_data *data)
{
	data->x = WINDOW_W;
	data->y = WINDOW_H;
	data->file = mlx_new_image(data->mlx_ptr, data->x, data->y);
	data->addr = mlx_get_data_addr(data->file, &data->bpp,
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
