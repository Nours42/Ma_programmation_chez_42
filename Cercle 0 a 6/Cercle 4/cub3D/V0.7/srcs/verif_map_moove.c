/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_moove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:50:43 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/21 15:23:54 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	go_right(t_data *data)
{
	data->map[data->line][data->index] = '2';
	data->index++;
}

void	go_left(t_data *data)
{
	data->map[data->line][data->index] = '2';
	data->index--;
}

void	go_down(t_data *data)
{
	data->map[data->line][data->index] = '2';
	data->line++;
}

void	go_up(t_data *data)
{
	data->map[data->line][data->index] = '2';
	data->line--;
}
