/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_mooves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:40:05 by kaly              #+#    #+#             */
/*   Updated: 2023/09/25 17:02:44 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_move_back(t_data *data)
{
	data->anglerad = data->player_orient * (M_PI / 180.00);
	data->xa = 10 * sin(data->anglerad) * (-1);
	data->ya = 10 * cos(data->anglerad);
	data->player_x -= (int)data->xa;
	data->player_y -= (int)data->ya;
}

void	ft_move_up(t_data *data)
{
	data->anglerad = data->player_orient * (M_PI / 180.00);
	data->xa = 10 * sin(data->anglerad) * (-1);
	data->ya = 10 * cos(data->anglerad);
	data->player_x += (int)data->xa;
	data->player_y += (int)data->ya;
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
		ft_quit(data);
	if (keysym == 65362)
		data->horizon += 20;
	if (keysym == 65364)
		data->horizon -= 20;
	if (keysym == 119)
		ft_move_up(data);
	if (keysym == 115)
		ft_move_back(data);
	if (keysym == 97 || keysym == 65361)
	{
		data->player_orient += 2.00;
		if (data->player_orient >= 180)
			data->player_orient -= 360;
	}
	if (keysym == 100 || keysym == 65363)
	{
		data->player_orient -= 2.00;
		if (data->player_orient <= -180)
			data->player_orient += 360;
	}
	ft_fill_floor(data);
	return (0);
}
