/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_calcul_distances.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:40:05 by kaly              #+#    #+#             */
/*   Updated: 2023/09/27 08:24:59 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calcul_distance(t_data *data)
{
	int	i;

	d->beta = 30.00;
	d->orient = d->player_orient + d->beta;
	d->x = 0;
	while (d->x < WINDOW_W)
	{
		if (d->orient >= 180)
			d->orient -= 360.00;
		if (d->orient <= -180)
			d->orient += 360.00;
		ft_init_delta(data);
		d->y = d->horizon - (100 / d->dist * 1000);
		i = -1;
		while ((d->y) < d->horizon + (100 / d->dist * 1000))
		{
			if (d->y >= 0 && d->y < WINDOW_H)
				calcul_distance_part_one(data);
			d->y++;
		}
		d->x++;
		d->beta -= 0.03125;
		d->orient -= 0.03125;
	}
	return ;
}

void	calcul_distance_part_one(t_data *data)
{
	if (++i == 0)
		d->origin_y = d->y;
	d->draw_y = d->y - d->origin_y;
	d->pixel_y = d->draw_y * d->wall_n_height / ((d->horizon - d->origin_y)
			* 2) + 1;
	if (d->dist_x <= d->dist_y)
	{
		if ((d->orient > 0 && d->orient < 90) || (d->orient > -90
				&& d->orient < 0))
			d->pixel_x = (d->player_y + (int)(d->first_xa + d->xa * d->i))
				% PXL;
		else
			d->pixel_x = (d->player_y - (int)(d->first_xa + d->xa * d->i + \
				1.00)) % PXL;
	}
	else
	{
		if (d->orient > 0)
			d->pixel_x = (d->player_x - (int)(d->first_ya + d->ya * d->o + \
				1.00)) % PXL;
		else
			d->pixel_x = (d->player_x + (int)(d->first_ya + d->ya * d->o))
				% PXL;
	}
	calcul_distance_part_two(data);
}

void	calcul_distance_part_two(t_data *data)
{
	if (((d->orient > 0 && d->orient < 90) && d->dist_x < d->dist_y)
		|| (d->orient > 90 && d->dist_x < d->dist_y))
		my_mlx_pixel(data, d->x, d->y, pix_text(data, d->wall_n_addr, \
			d->wall_n_line_length, d->wall_n_bpp));
	else if (((d->orient < 0 && d->orient > -90) && d->dist_x < d->dist_y)
		|| (d->orient < -90 && d->dist_x < d->dist_y))
		my_mlx_pixel(data, d->x, d->y, pix_text(data, d->wall_s_addr, \
			d->wall_s_line_length, d->wall_s_bpp));
	else if (((d->orient > 0 && d->orient < 90) && d->dist_x > d->dist_y)
		|| ((d->orient < 0 && d->orient > -90) && d->dist_x > d->dist_y))
		my_mlx_pixel(data, d->x, d->y, pix_text(data, d->wall_e_addr, \
			d->wall_e_line_length, d->wall_e_bpp));
	else
		my_mlx_pixel(data, d->x, d->y, pix_text(data, d->wall_w_addr, \
			d->wall_w_line_length, d->wall_w_bpp));
}

void	ft_init_wall_img(t_data *d)
{
	d->wall_n = mlx_xpm_file_to_image(d->mlx_ptr, "./img/down.xpm",
			&d->wall_n_width, &d->wall_n_height);
	d->wall_n_addr = mlx_get_data_addr(d->wall_n, &d->wall_n_bpp,
			&d->wall_n_line_length, &d->wall_n_endian);
	d->wall_e = mlx_xpm_file_to_image(d->mlx_ptr, "./img/black_window.xpm",
			&d->wall_e_width, &d->wall_e_height);
	d->wall_e_addr = mlx_get_data_addr(d->wall_e, &d->wall_e_bpp,
			&d->wall_e_line_length, &d->wall_e_endian);
	d->wall_s = mlx_xpm_file_to_image(d->mlx_ptr, "./img/red_window.xpm",
			&d->wall_s_width, &d->wall_s_height);
	d->wall_s_addr = mlx_get_data_addr(d->wall_s, &d->wall_s_bpp,
			&d->wall_s_line_length, &d->wall_s_endian);
	d->wall_w = mlx_xpm_file_to_image(d->mlx_ptr, "./img/window.xpm",
			&d->wall_w_width, &d->wall_w_height);
	d->wall_w_addr = mlx_get_data_addr(d->wall_w, &d->wall_w_bpp,
			&d->wall_w_line_length, &d->wall_w_endian);
	return ;
}
