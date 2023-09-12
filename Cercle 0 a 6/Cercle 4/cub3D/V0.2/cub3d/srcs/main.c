/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:47:16 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/12 16:42:39 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	mlx_close(t_data *data)
{
	mlx_destroy_image(data->mlx->mlx, data->image->image_ptr);
	mlx_destroy_window(data->mlx->mlx, data->mlx->window);
	mlx_destroy_display(data->mlx->mlx);
	free(data->mlx->mlx);
	exit(0);
}

int	init_params(t_data *data)
{
	data->mlx->scale = 100;
	data->mlx->center_x = 0.0;
	data->mlx->center_y = 0.0;
	data->mlx->max_iter = 100;
	data->map->color_map_hex = strdup(get_map_color(data));
	ft_printf("%s\n", data->map->color_map_hex);
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

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->image = (t_image *)malloc(sizeof(t_image));
	data->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	data->map = (t_map *)malloc(sizeof(t_map));
	ft_check(argc, argv, data->map);
	init_params(data);
	ft_printf("%s\n", data->map->color_map_hex);
	data->mlx->mlx = mlx_init();
	data->mlx->window = mlx_new_window(data->mlx->mlx, WINDOW_W, WINDOW_H, "cub3d");
	data->image->image_ptr = mlx_new_image(data->mlx->mlx, WINDOW_W, WINDOW_H);
	data->image->data_addr = (int *)mlx_get_data_addr(data->image->image_ptr,
			&data->image->bits_per_pixel, &data->image->size_line, &data->image->endian);
	mlx_hook(data->mlx->window, 17, 0, mlx_close, &data->mlx);
	mlx_key_hook(data->mlx->window, key_controls, &data->mlx);
	mlx_mouse_hook(data->mlx->window, mouse_controls, &data->mlx);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->window, data->image->image_ptr, 0, 0);
	mlx_loop(data->mlx->mlx);
	return (0);
}
