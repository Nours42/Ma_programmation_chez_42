/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:45:34 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/25 11:35:08 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	moving(int key, t_mlx *mlx)
{
	if (key == UP)
		mlx->center_y -= (double)(MOVING_FACTOR) / (mlx->scale);
	if (key == DOWN)
		mlx->center_y += (double)(MOVING_FACTOR) / (mlx->scale);
	if (key == LEFT)
		mlx->center_x -= (double)(MOVING_FACTOR) / (mlx->scale);
	if (key == RIGHT)
		mlx->center_x += (double)(MOVING_FACTOR) / (mlx->scale);
}

int	key_controls(int key, t_mlx *mlx)
{
	if (key == 65307)
		mlx_close(mlx);
	else if (key == PLUS)
		mlx->scale *= SCALE_FACTOR;
	else if (key == MINUS)
		mlx->scale /= SCALE_FACTOR;
	else if (key == R_KEY)
		init_params(mlx, 1);
	else if (key >= 65361 && key <= 65364)
		moving(key, mlx);
	else if (key == SPACE)
		set_colors(mlx, 1);
	else if (key == L_KEY)
		mlx->max_iter += 500;
	else if (key == K_KEY && mlx->max_iter >= 600)
		mlx->max_iter -= 500;
	else if (key == N_KEY)
		init_params(mlx, 1);
	else
		return (0);
	rerender(mlx);
	return (1);
}

int	mouse_controls(int button, int x, int y, t_mlx *mlx)
{
	mlx_mouse_get_pos(mlx->mlx, mlx->window, &x, &y);
	if (x != mlx->center_x || y != mlx->center_y)
	{
		mlx->center_y = ((y - WINDOW_H / 2) / mlx->scale + mlx->center_y);
		mlx->center_x = ((x - WINDOW_W / 2) / mlx->scale + mlx->center_x);
	}
	if (button == MOUSE_LEFT || button == WHEEL_DOWN)
	{
		mlx->scale *= SCALE_FACTOR;
		mlx->max_iter += SCALE_ITER;
	}
	if (button == MOUSE_RIGHT || button == WHEEL_UP)
	{
		mlx->scale /= SCALE_FACTOR;
		mlx->max_iter -= SCALE_ITER;
	}
	rerender(mlx);
	return (1);
}
