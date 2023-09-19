/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_floor_and_ceiling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:38:27 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/19 15:57:06 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int search_floor_or_ceiling(t_data *data, char c)
{
	int i;
	int j;
	
	i = data->EA_texture + 1;
	j = 0;
	while (data->map[i])
	{
		while(data->map[i][j])
		{
			if (data->map[i][j] == c && data->map[i][j + 1] == ' ')
				return (i);
			j++;
		}
		i++;
		j = 0;
	}
	return (-1);
}

int floor_ceiling_found(t_data *data)
{
	data->index_Floor = (search_floor_or_ceiling(data, 'F'));
	data->index_Ceiling = (search_floor_or_ceiling(data, 'C'));
	if (data->index_Floor == -1)
		return (titre_err(" FLOOR manquant "));
	else
		ft_printf("Floor :\t\t\t\t\033[32mOK\033[0m\n");
	if (data->index_Ceiling == -1)
		return (titre_err(" CEILING manquant "));
	else
		ft_printf("Ceiling :\t\t\t\033[32mOK\033[0m\n");
	return (0);
}

int	floor_ceiling_format_validation(char *s, int i)
{
	int		j;
	int		k;
	char	*s2;

	s2 = s + 2;
	j = 1;
	if ((i == 1 && ft_strncmp(s, "F ", 2) != 0)
		|| (i == 2 && ft_strncmp(s, "C ", 2) != 0))
		return (1);
	while (j < 4)
	{
		k = color_verif(s2);
		if (k == 1)
		{
			if (j == 1)
				return (titre_err(" 1st color "));
			if (j == 2)
				return (titre_err(" 2nd color "));
			if (j == 3)
				return (titre_err(" 3rd color "));
		}
			s2 += k;
		j++;
	}
	return (0);
}

int	color_verif(char *s)
{
	int	i;

	if(s)
	{
		i = ft_atoi(s);
		if (i < 0 || i > 255)
			return (1);
		if (i < 10)
			return (2);
		if (i < 100)
			return (3);
		else
			return (4);
	}
	return (0);
}

int		floor_ceiling_validation(t_data *data)
{
	if (floor_ceiling_found(data))
		return(err("error in search of Floor and Ceiling"));
	else
	{
		floor_ceiling_format_validation(data->map[data->index_Floor], 1);
		floor_ceiling_format_validation(data->map[data->index_Ceiling], 2);
	}
	return (0);
}
