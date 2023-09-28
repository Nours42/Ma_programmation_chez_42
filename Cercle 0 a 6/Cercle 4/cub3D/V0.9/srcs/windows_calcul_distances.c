/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_calcul_distances.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:40:05 by kaly              #+#    #+#             */
/*   Updated: 2023/09/27 15:10:04 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calcul_distance(t_data *data)
{
	int	i;

	while (data->x < WINDOW_W)
	{
		if (data->orient >= 180)
			data->orient -= 360.00;
		if (data->orient <= -180)
			data->orient += 360.00;
		ft_init_delta(data);
		i = -1;
		while ((data->y) < data->horizon + (100 / data->dist * 1000))
		{
			if (++i == 0)
					data->origin_y = data->y;
			if (data->y >= 0 && data->y < WINDOW_H)
				calcul_distance_part_one(data);
			data->y++;
		}
		data->x++;
		data->beta -= 0.03125;
		data->orient -= 0.03125;
	}
}

void	calcul_distance_part_one(t_data *data)
{
	data->draw_y = data->y - data->origin_y;
	data->pixel_y = data->draw_y * data->wall_n_height / ((data->horizon - \
		data->origin_y) * 2) + 1;
	if (data->dist_x <= data->dist_y)
	{
		if ((data->orient > 0 && data->orient < 90) || (data->orient > -90
				&& data->orient < 0))
			data->pixel_x = (data->player_y + (int)(data->first_xa + data->xa
						* data->i)) % PXL;
		else
			data->pixel_x = (data->player_y - (int)(data->first_xa + data->xa
						* data->i + 1.00)) % PXL;
	}
	else
	{
		if (data->orient > 0)
			data->pixel_x = (data->player_x - (int)(data->first_ya + data->ya
						* data->o + 1.00)) % PXL;
		else
			data->pixel_x = (data->player_x + (int)(data->first_ya + data->ya
						* data->o)) % PXL;
	}
	calcul_distance_part_two(data);
}

void	calcul_distance_part_two(t_data *data)
{
	if (((data->orient > 0 && data->orient < 90) && data->dist_x < data->dist_y)
		|| (data->orient > 90 && data->dist_x < data->dist_y))
		my_mlx_pixel(data, data->x, data->y, pix_text(data, data->wall_n_addr, \
		data->wall_n_line_length, data->wall_n_bpp));
	else if (((data->orient < 0 && data->orient > -90)
			&& data->dist_x < data->dist_y) || (data->orient < -90
			&& data->dist_x < data->dist_y))
		my_mlx_pixel(data, data->x, data->y, pix_text(data, data->wall_s_addr, \
		data->wall_s_line_length, data->wall_s_bpp));
	else if (((data->orient > 0 && data->orient < 90)
			&& data->dist_x > data->dist_y) || ((data->orient < 0
				&& data->orient > -90) && data->dist_x > data->dist_y))
		my_mlx_pixel(data, data->x, data->y, pix_text(data, data->wall_e_addr, \
		data->wall_e_line_length, data->wall_e_bpp));
	else
		my_mlx_pixel(data, data->x, data->y, pix_text(data, data->wall_w_addr, \
		data->wall_w_line_length, data->wall_w_bpp));
}

void	ft_init_wall_img(t_data *data)
{
	data->wall_n = mlx_xpm_file_to_image(data->mlx_ptr, data->no_texture,
			&data->wall_n_width, &data->wall_n_height);
	data->wall_n_addr = mlx_get_data_addr(data->wall_n, &data->wall_n_bpp,
			&data->wall_n_line_length, &data->wall_n_endian);
	data->wall_e = mlx_xpm_file_to_image(data->mlx_ptr, \
		data->ea_texture, &data->wall_e_width, &data->wall_e_height);
	data->wall_e_addr = mlx_get_data_addr(data->wall_e, &data->wall_e_bpp,
			&data->wall_e_line_length, &data->wall_e_endian);
	data->wall_s = mlx_xpm_file_to_image(data->mlx_ptr, data->so_texture,
			&data->wall_s_width, &data->wall_s_height);
	data->wall_s_addr = mlx_get_data_addr(data->wall_s, &data->wall_s_bpp,
			&data->wall_s_line_length, &data->wall_s_endian);
	data->wall_w = mlx_xpm_file_to_image(data->mlx_ptr, data->we_texture,
			&data->wall_w_width, &data->wall_w_height);
	data->wall_w_addr = mlx_get_data_addr(data->wall_w, &data->wall_w_bpp,
			&data->wall_w_line_length, &data->wall_w_endian);
	return ;
}
