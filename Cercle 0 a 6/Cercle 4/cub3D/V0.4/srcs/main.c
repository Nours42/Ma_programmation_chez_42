/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:18:13 by kaly              #+#    #+#             */
/*   Updated: 2023/09/16 18:57:14 by jmetezea         ###   ########.fr       */
=======
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:47:16 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/14 15:49:14 by sdestann         ###   ########.fr       */
>>>>>>> fc43c40293e881edf2f65252a4cdbe41522467b8
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

<<<<<<< HEAD
void	init_data(t_data *data)
{
	char *s;
	
	data->x = WINDOW_W;
	data->y = WINDOW_H;
	data->exit = 1;
	data->index_first_lane = 6;
	s = get_map_color("42\0", 4, data);
	data->color_map_hex_F = ft_htoi(s);
	free(s);
	s = get_map_color("42\0", 5, data);
	data->color_map_hex_C = ft_htoi(s);
	free(s);
=======
int	mlx_close(t_data *data)
{
	// mlx_destroy_image(data->mlx->mlx, data->image->image_ptr);

	
	// mlx_destroy_window(data->mlx->mlx, data->mlx->window);
	// mlx_destroy_display(data->mlx->mlx);
	ft_clean_all(data);
	return (1);
}

int	init_params(t_data *data)
{
	char *s;

	data->mlx->scale = 100;
	data->mlx->center_x = 0.0;
	data->mlx->center_y = 0.0;
	data->mlx->x = WINDOW_H;
	data->mlx->y = WINDOW_W;
	data->mlx->pxl = 50;
	s = get_map_color("42\0", 4, data);
	data->map->color_map_hex_F = ft_htoi(s);
	free(s);
	s = get_map_color("42\0", 5, data);
	data->map->color_map_hex_C = ft_htoi(s);
	free(s);
	return (0);
}

int	rerender(t_data *data)
{
	mlx_destroy_image(data->mlx->mlx, data->image->image_ptr);
	data->image->image_ptr = mlx_new_image(data->mlx->mlx, WINDOW_W, WINDOW_H);
	data->image->data_addr = (int *)mlx_get_data_addr(data->image->image_ptr,
			&(data->image->bits_per_pixel), &(data->image->size_line),
			&(data->image->endian));
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->window, data->image->image_ptr, 0, 0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->image->addr + (y * data->image->line_length + x * (data->image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_fill_floor(t_data *data)
{
	data->image->image_ptr = mlx_new_image(data->mlx->mlx, data->mlx->x, data->mlx->y);
	data->image->addr = mlx_get_data_addr(data->image->image_ptr, &data->image->bits_per_pixel,
							&data->image->line_length, &data->image->endian);
	data->mlx->y = 0;
	while ((data->mlx->y) < WINDOW_H)
	{
		data->mlx->x = 0;
		while ((data->mlx->x) < WINDOW_W)
		{
			if (data->mlx->y < WINDOW_H / 2)
				my_mlx_pixel_put(data, data->mlx->x, data->mlx->y, data->map->color_map_hex_C);
			else
				my_mlx_pixel_put(data, data->mlx->x, data->mlx->y, data->map->color_map_hex_F);
			data->mlx->x++;
		}
		data->mlx->y++;
	}
	mlx_put_image_to_window (data->mlx->mlx, data->mlx->window, data->image->image_ptr, 
								0, 0);
}

void	ft_create_window(t_data *data)
{
	data->mlx->mlx = mlx_init();
	if (data->mlx->mlx == NULL)
		return ;
	data->mlx->window = mlx_new_window(data->mlx->mlx, WINDOW_W,
			WINDOW_H, "Cub3d");
	if (data->mlx->window == NULL)
	{
		free(data->mlx->window);
		return ;
	}
	// mlx_hook(data->mlx->window, 17, 1L << 0, mlx_close, &data->mlx);
	mlx_hook(data->mlx->window, 2, 1L << 0, key_controls, &data->mlx);
	// mlx_mouse_hook(data->mlx->window, mouse_controls, &data->mlx);
	ft_fill_floor(data);
	// ft_raytraycing(data);
	// mlx_loop_hook(data->mlx->mlx, rerender, &data->mlx);
	mlx_loop(data->mlx->mlx);
	mlx_destroy_window(data->mlx->mlx, data->mlx->window);
	mlx_destroy_display(data->mlx->mlx);
>>>>>>> fc43c40293e881edf2f65252a4cdbe41522467b8
}

int	main(int argc, char **argv)
{
	t_data	*data;

<<<<<<< HEAD
	ft_check_arg(argc, argv);
	data = malloc(sizeof(t_data));
	if (!data)
		return (MLX_ERROR);
	if (ft_check(argc, argv, data) == 1)
		ft_clean_when_verif_map_ko(data);
	init_data(data);
	ft_create_window(data);
	// ft_quit(data);
=======
	if (argc > 1)
	{
		data = (t_data *)malloc(sizeof(t_data));
		data->map = (t_map *)malloc(sizeof(t_map));
		if (ft_check(argc, argv, data) == 1)
			ft_clean_when_verif_map_ko(data);
		data->mlx = (t_mlx *)malloc(sizeof(t_mlx));
		init_params(data);
		data->image = (t_image *)malloc(sizeof(t_image));
		test_gps(data);
		ft_create_window(data);
		game_over(data);
	}
	else
		return (err("ou est la carte ?\n"));
>>>>>>> fc43c40293e881edf2f65252a4cdbe41522467b8
	return (0);
}
