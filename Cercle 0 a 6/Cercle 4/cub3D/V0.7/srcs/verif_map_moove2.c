/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_moove2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:50:43 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/21 16:39:14 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	go_right_f(t_data *data)
{
	data->map[data->line][data->index] = '3';
	data->index++;
}

void	go_left_f(t_data *data)
{
	data->map[data->line][data->index] = '3';
	data->index--;
}

void	go_down_f(t_data *data)
{
	data->map[data->line][data->index] = '3';
	data->line++;
}

void	go_up_f(t_data *data)
{
	data->map[data->line][data->index] = '3';
	data->line--;
}
