/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_mooves2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:40:05 by kaly              #+#    #+#             */
/*   Updated: 2023/09/27 08:04:06 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_strafe_right(t_data *data)
{
	data->player_orient += 90.00;
	if (data->player_orient >= 180)
		data->player_orient -= 360;
	data->anglerad = data->player_orient * (M_PI / 180.00);
	data->xa = 150 * sin(data->anglerad) * (-1);
	data->ya = 150 * cos(data->anglerad);
	data->check_y = (data->player_y - (int)data->ya) / PXL;
	data->check_x = (data->player_x - (int)data->xa) / PXL;
	if (data->map[(int)data->check_x][(int)data->check_y] != '1')
	{
		data->player_x -= (int)data->xa / 5;
		data->player_y -= (int)data->ya / 5;
	}
	data->player_orient -= 90.00;
	if (data->player_orient <= -180)
		data->player_orient += 360;
}

void	ft_strafe_left(t_data *data)
{
	data->player_orient -= 90.00;
	if (data->player_orient <= -180)
		data->player_orient += 360;
	data->anglerad = data->player_orient * (M_PI / 180.00);
	data->xa = 150 * sin(data->anglerad) * (-1);
	data->ya = 150 * cos(data->anglerad);
	data->check_y = (data->player_y - (int)data->ya) / PXL;
	data->check_x = (data->player_x - (int)data->xa) / PXL;
	if (data->map[(int)data->check_x][(int)data->check_y] != '1')
	{
		data->player_x -= (int)data->xa / 5;
		data->player_y -= (int)data->ya / 5;
	}
	data->player_orient += 90.00;
	if (data->player_orient >= 180)
		data->player_orient -= 360;
}

void	ft_turn_right(t_data *data)
{
	data->player_orient -= 5.00;
	if (data->player_orient <= -180)
		data->player_orient += 360;
}

void	ft_turn_left(t_data *data)
{
	data->player_orient += 5.00;
	if (data->player_orient >= 180)
		data->player_orient -= 360;
}
