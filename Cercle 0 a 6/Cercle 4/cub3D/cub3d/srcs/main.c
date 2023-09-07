/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:47:16 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/07 16:57:24 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	mlx_close(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->image.image_ptr);
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
}

int	init_params(t_mlx *mlx)
{
	mlx->scale = 100;
	mlx->center_x = 0.0;
	mlx->center_y = 0.0;
	mlx->max_iter = 100;
	return (0);
}

int	rerender(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->image.image_ptr);
	mlx->image.image_ptr = mlx_new_image(mlx->mlx, WINDOW_W, WINDOW_H);
	mlx->image.data_addr = (int *)mlx_get_data_addr(mlx->image.image_ptr,
			&(mlx->image.bits_per_pixel), &(mlx->image.size_line),
			&(mlx->image.endian));
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image.image_ptr, 0, 0);
	return (0);
}

// int	main(void)
// {
// 	t_mlx	mlx;

// 	init_params(&mlx);
// 	mlx.mlx = mlx_init();
// 	mlx.window = mlx_new_window(mlx.mlx, WINDOW_W, WINDOW_H, "cub3d");
// 	mlx.image.image_ptr = mlx_new_image(mlx.mlx, WINDOW_W, WINDOW_H);
// 	mlx.image.data_addr = (int *)mlx_get_data_addr(mlx.image.image_ptr,
// 			&mlx.image.bits_per_pixel, &mlx.image.size_line, &mlx.image.endian);
// 	mlx_hook(mlx.window, 17, 0, mlx_close, &mlx);
// 	mlx_key_hook(mlx.window, key_controls, &mlx);
// 	mlx_mouse_hook(mlx.window, mouse_controls, &mlx);
// 	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.image.image_ptr, 0, 0);
// 	mlx_loop(mlx.mlx);
// 	return (0);
// }
