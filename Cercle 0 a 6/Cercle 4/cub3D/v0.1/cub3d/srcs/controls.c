/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:57:13 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/11 12:48:07 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	moving(int key, t_data *data)
{
	if (key == UP)
		data->mouse->center_y -= (double)(MOVING_FACTOR) / (data->image->scale);
	if (key == DOWN)
		data->mouse->center_y += (double)(MOVING_FACTOR) / (data->image->scale);
	if (key == LEFT)
		data->mouse->center_x -= (double)(MOVING_FACTOR) / (data->image->scale);
	if (key == RIGHT)
		data->mouse->center_x += (double)(MOVING_FACTOR) / (data->image->scale);
}

int	key_controls(int key, t_data *data)
{
	if (key == 65307)
		mlx_close(data);
	else if (key == PLUS)
		data->image->scale *= SCALE_FACTOR;
	else if (key == MINUS)
		data->image->scale /= SCALE_FACTOR;
	else if (key == R_KEY)
		init_params(data);
	else if (key >= 65361 && key <= 65364)
		moving(key, data);
	else if (key == N_KEY)
		init_params(data);
	else
		return (0);
	rerender(data);
	return (1);
}

int	mouse_controls(int button, int x, int y, t_data *data)
{
	mlx_mouse_get_pos(data->mlx->mlx, data->mlx->window, &x, &y);
	if (x != data->mouse->center_x || y != data->mouse->center_y)
	{
		data->mouse->center_y = ((y - WINDOW_H / 2) / data->image->scale
				+ data->mouse->center_y);
		data->mouse->center_x = ((x - WINDOW_W / 2) / data->image->scale
				+ data->mouse->center_x);
	}
	if (button == MOUSE_LEFT || button == WHEEL_DOWN)
	{
		data->image->scale *= SCALE_FACTOR;
	}
	if (button == MOUSE_RIGHT || button == WHEEL_UP)
	{
		data->image->scale /= SCALE_FACTOR;
	}
	rerender(data);
	return (1);
}
