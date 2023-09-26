/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:50:43 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/26 12:12:21 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	first_step(t_data *data)
{
	data->line = data->map_first_line;
	data->index = 0;
	while (data->map[data->line][data->index] == ' ')
		data->index++;
	if (data->map[data->line][data->index] == '1')
		data->first_index = data->index;
	data->map[data->line][data->index] = '4';
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
	data->map_last_line = i;
	while (begin_by_one(data->map[i]) && ends_by_one(data->map[i]))
		i--;
	data->map_first_line = i + 1;
}
