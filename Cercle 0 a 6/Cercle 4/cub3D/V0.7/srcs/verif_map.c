/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:50:43 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/21 16:40:50 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	go_around_the_walls(t_data *data)
{
	int	i;

	i = 0;
	data->line = data->Map_first_line;
	data->index = 0;
	while (data->map[data->line][data->index] == ' '
		|| data->map[data->line][data->index] == '\t')
		data->index++;
	if (data->map[data->line][data->index] == '1')
		data->first_index = data->index;
	data->map[data->line][data->index] = '4';
	if (data->map[data->line][data->index + 1] == '1')
	{
		data->index++;
		while (data->line != data->Map_first_line
			|| data->index != data->first_index)
		{
			i++;
			if (data->map[data->line][data->index + 1] == '1')
				go_right(data);
			else if (((((data->line != data->Map_first_line)
							&& (data->map[data->line - 1][data->index] == '4'))
					|| ((data->index != 0
							&& data->map[data->line][data->index - 1] == '4'))
				|| ((data->line != data->Map_last_line)
					&& (data->map[data->line + 1][data->index] == '4'))
				|| (data->map[data->line][data->index + 1] == '4'))
							&& (data->map[data->line][data->index] != '2')
							&& i > 2))
			{
				print_map(data, data->Map_first_line - 1);
				return (0);
			}
			else if ((data->line != data->Map_first_line)
				&& (data->map[data->line - 1][data->index] == '1'))
				go_up(data);
			else if (data->map[data->line][data->index - 1] == '1')
				go_left(data);
			else if ((data->line != data->Map_last_line)
				&& (data->map[data->line + 1][data->index] == '1'))
				go_down(data);
			else if ((data->line != data->Map_last_line)
				&& (data->map[data->line + 1][data->index] == '2'))
				go_down_f(data);
			else if (data->map[data->line][data->index - 1] == '2')
				go_left_f(data);
			else if (data->map[data->line - 1][data->index] == '2')
				go_up_f(data);
			else if (data->map[data->line][data->index + 1] == '2')
				go_right_f(data);
			else
				return (1);
		}
	}
	return (1);
}

int	begin_by_one(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == 49)
		return (1);
	return (0);
}

int	ends_by_one(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i -= 2;
	while (s[i] == ' ' || s[i] == '\t')
		i--;
	if (s[i] == '1')
		return (1);
	return (0);
}

void	find_start_end_of_map(t_data *data)
{
	int		i;

	i = 0;
	while (data->map[i])
		i++;
	i--;
	while (empty_line(data->map[i]))
		i--;
	data->Map_last_line = i;
	while (begin_by_one(data->map[i]) && ends_by_one(data->map[i]))
		i--;
	data->Map_first_line = i + 1;
}
