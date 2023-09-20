/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:50:43 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/20 10:36:47 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	search_map(t_data *data)
{
	if (map_validation(data))
		return (1);
	else
		ft_printf("structure de la map :\t\t\033[32mOK\033[0m\n\n");
	return (0);
}

int	is_valid_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
	{
		if (s[i] == ' ' || s[i] =='\t' || s[i] =='0' || s[i] =='1'
			|| s[i] =='E' || s[i] =='N' || s[i] =='S' || s[i] =='W')
		i++;
		else
			return (1);
	}
	return (0);
}

int	begin_by_one(char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == 49)
		return (0);
	return (1);
}

int	ends_by_one(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	i -= 2;
	while (s[i] == 32)
		i--;
	if (s[i] == 49)
		return (0);
	return (1);
}

// int	structure_of_wall_verif(t_data *data)
// {
	
// }

int map_validation(t_data *data)
{
	int		i;

	i = data->index_Ceiling;
	while (data->map[++i])
	{
		if(is_valid_line(data->map[i]))
			return (titre_err(" car. incorrect "));
		else if (begin_by_one(data->map[i]) || ends_by_one(data->map[i]))
			return (titre_err(" mur ouvert "));
	}
	data->index_last_line = i - 1;
	return (0);
}
