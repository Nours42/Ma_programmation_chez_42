/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:40:05 by kaly              #+#    #+#             */
/*   Updated: 2023/09/27 08:25:07 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_length + x * (d->bpp / 8));
	*(unsigned int *)dst = color;
}

int	pix_text(t_data *data, char *addr, int line_lenght, int bpp)
{
	int	color;

	color = *(unsigned int *)(addr + (d->pixel_y * line_lenght
				+ (d->pixel_x / 2) * (bpp / 8)));
	return (color);
}

int	render(t_data *d)
{
	if (d->win_ptr != NULL)
	{
		if (d->exit == 0)
		{
			mlx_destroy_window(d->mlx_ptr, d->win_ptr);
			d->win_ptr = NULL;
		}
	}
	return (0);
}

void	ft_create_window(t_data *d)
{
	d->mlx_ptr = mlx_init();
	if (d->mlx_ptr == NULL)
		return ;
	d->win_ptr = mlx_new_window(d->mlx_ptr, WINDOW_W,
			WINDOW_H, "Zelda");
	if (d->win_ptr == NULL)
	{
		free(d->win_ptr);
		return ;
	}
	ft_init_wall_img(data);
	mlx_hook(d->win_ptr, 2, 0, &handle_keypress, data);
	mlx_hook(d->win_ptr, 17, 1L << 0, &ft_quit, data);
	mlx_loop_hook(d->mlx_ptr, &render, data);
	d->player_orient = 90.01;
	ft_fill_floor(data);
	mlx_loop(d->mlx_ptr);
	mlx_destroy_display(d->mlx_ptr);
}

void	ft_fill_floor(t_data *d)
{
	d->x = WINDOW_W;
	d->y = WINDOW_H;
	d->file = mlx_new_image(d->mlx_ptr, d->x, d->y);
	d->addr = mlx_get_data_addr(d->file, &d->bpp,
			&d->line_length, &d->endian);
	d->y = 0;
	while ((d->y) < WINDOW_H)
	{
		d->x = 0;
		while ((d->x) < WINDOW_W)
		{
			if (d->y < d->horizon)
				my_mlx_pixel(data, d->x, d->y, d->color_map_hex_c);
			else
				my_mlx_pixel(data, d->x, d->y, d->color_map_hex_f);
			d->x++;
		}
		d->y++;
	}
	calcul_distance(data);
	mlx_put_image_to_window (d->mlx_ptr, d->win_ptr, d->file, 0, 0);
	mlx_destroy_image(d->mlx_ptr, d->file);
}
