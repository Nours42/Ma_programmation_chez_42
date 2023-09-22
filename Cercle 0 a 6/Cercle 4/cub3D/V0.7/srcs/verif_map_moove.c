/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_moove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:50:43 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/22 13:37:59 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	test_map_ok (t_data *data, int i)
{
	if ((((data->line != data->Map_first_line)
			&& (data->map[data->line - 1])
			&& (data->map[data->line - 1][data->index])
			&& (data->map[data->line - 1][data->index] == '4'))
		|| ((data->index != 0
			&& data->map[data->line][data->index - 1]
			&& data->map[data->line][data->index - 1] == '4'))
		|| ((data->line != data->Map_last_line)
			&& (data->map[data->line + 1])
			&& (data->map[data->line + 1][data->index])
			&& (data->map[data->line + 1][data->index] == '4'))
		|| ((data->map[data->line][data->index + 1])
			&& (data->map[data->line][data->index + 1] == '4')))
			&& (data->map[data->line][data->index] != '2')
			&& i > 2)
	{
		print_map(data, data->Map_first_line - 1);
		return (1);
	}
	else
		return (0);
}

int	verif_sides(t_data *data, int i, int j)
{
	if ((data->map[data->line][data->index + i])
		&& (data->map[data->line][data->index + i] == j))
		return (1);
	return (0);
}

int verif_up_or_down(t_data *data, int i, int j)
{
	if (i == -1)
	{
		if ((data->line != data->Map_first_line)
		&& (data->map[data->line + i][data->index])
		&& (data->map[data->line + i][data->index] == j))
		return (1);
	}
	else if (i == 1)
	{
		if ((data->line != data->Map_last_line)
		&& (data->map[data->line + i])
		&& (data->map[data->line + i][data->index])
		&& (data->map[data->line + i][data->index] == j))
		return (1);
	}
	return (0);
}

void	go_sides(t_data *data, int i, int j)
{
	data->map[data->line][data->index] = j;
	data->index += i;
}

void	go_up_or_down(t_data *data, int i, int j)
{
	data->map[data->line][data->index] = j;
	data->line += i;
}