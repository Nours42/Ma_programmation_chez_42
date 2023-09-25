/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_around_the_walls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:50:43 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/25 12:43:11 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	go_around_the_walls(t_data *data)
{
	first_step(data);
	if (data->map[data->line][data->index + 1] == '1')
	{
		data->index++;
		if (go_around_the_walls2(data, 0))
			return (1);
		else
			return (0);
	}
	return (1);
}

int	go_around_the_walls2(t_data *d, int i)
{
	while (d->line != d->Map_first_line || d->index != d->first_index)
	{
		i++;
		if (test_map_ok(d, i))
			return (0);
		else if (verif_sides(d, 1, '1'))
			go_sides(d, 1, '2');
		else if (verif_up_or_down(d, -1, '1'))
			go_up_or_down(d, -1, '2');
		else if (verif_sides(d, -1, '1'))
			go_sides(d, -1, '2');
		else if (verif_up_or_down(d, 1, '1'))
			go_up_or_down(d, 1, '2');
		else if (verif_up_or_down(d, 1, '2'))
			go_up_or_down(d, 1, '3');
		else if (verif_sides(d, -1, '2'))
			go_sides(d, -1, '3');
		else if (verif_up_or_down(d, -1, '2'))
			go_up_or_down(d, -1, '3');
		else if (verif_sides(d, 1, '2'))
			go_sides(d, 1, '3');
		else
			return (1);
	}
	return (0);
}
