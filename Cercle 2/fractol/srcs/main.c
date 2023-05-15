/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:40:09 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/02 14:15:07 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mlx_close(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->image.image_ptr);
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
}

void	set_colors(t_mlx *mlx, int mode)
{
	if (mode == 0)
	{
		mlx->color_r = 5;
		mlx->color_g = 3;
		mlx->color_b = 2;
	}
	else
	{
		mlx->color_r = (mlx->color_r + 5) % 12;
		mlx->color_g = (mlx->color_g + 3) % 14;
		mlx->color_b = (mlx->color_b + 6) % 17;
	}
}

int	init_params(t_mlx *mlx, char next_frac)
{
	if (next_frac)
		mlx->fractal_type = mlx->fractal_type % 4 + 1;
	else
		mlx->fractal_type = 1;
	mlx->scale = 100;
	mlx->center_x = 0.0;
	mlx->center_y = 0.0;
	mlx->max_iter = 100;
	mlx->julia_const.im = 0.756;
	mlx->julia_const.re = -0.1244;
	set_colors(mlx, 0);
	return (0);
}

int	rerender(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->image.image_ptr);
	mlx->image.image_ptr = mlx_new_image(mlx->mlx, WINDOW_W, WINDOW_H);
	mlx->image.data_addr = (int *)mlx_get_data_addr(mlx->image.image_ptr,
			&(mlx->image.bits_per_pixel), &(mlx->image.size_line),
			&(mlx->image.endian));
	draw_fractal(*mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image.image_ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	init_params(&mlx, 0);
	input_handler(argc, argv, &mlx);
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, WINDOW_W, WINDOW_H, "fractol");
	mlx.image.image_ptr = mlx_new_image(mlx.mlx, WINDOW_W, WINDOW_H);
	mlx.image.data_addr = (int *)mlx_get_data_addr(mlx.image.image_ptr,
			&mlx.image.bits_per_pixel, &mlx.image.size_line, &mlx.image.endian);
	mlx_hook(mlx.window, 17, 0, mlx_close, &mlx);
	mlx_key_hook(mlx.window, key_controls, &mlx);
	mlx_mouse_hook(mlx.window, mouse_controls, &mlx);
	draw_fractal(mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.image.image_ptr, 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
