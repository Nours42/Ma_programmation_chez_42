/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_floor_and_ceiling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:38:27 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/20 10:31:38 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int search_floor_or_ceiling(t_data *data, char c)
{
	int i;
	int j;
	char	*str;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while(data->map[i][j])
		{
			if (data->map[i][j] == c && data->map[i][j + 1] == ' ')
			{
				str = ft_strjoin(&c, " ");
				// ft_printf("str : '%s'", str);
				if (ft_strcmp(str, "F "))
					data->index_Floor = j;
				else
					data->index_Ceiling = j;
				free(str);
				return (i);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (-1);
}

int floor_ceiling_found(t_data *data)
{
	data->line_Floor = (search_floor_or_ceiling(data, 'F'));
	data->line_Ceiling = (search_floor_or_ceiling(data, 'C'));
	if (data->line_Floor == -1)
		return (titre_err(" FLOOR manquant "));
	else
		ft_printf("Floor :\t\t\t\t\033[32mPRESENT\033[0m\n");
	if (data->line_Ceiling == -1)
		return (titre_err(" CEILING manquant "));
	else
		ft_printf("Ceiling :\t\t\t\033[32mPRESENT\033[0m\n");
	return (0);
}

int	floor_format_validation(t_data *data)
{
	int		j;
	char	*s2;

	j = -1;
	s2 = data->map[data->line_Floor];
	while (++j <= data->index_Floor)
		s2++;
	s2 += 2;
	data->Floor_first_color = ft_atoi(s2);
	s2 = ft_strchr(s2, ',');
	s2++;
	data->Floor_second_color = ft_atoi(s2);
	s2 = ft_strchr(s2, ',');
	s2++;
	data->Floor_third_color = ft_atoi(s2);
	if ((data->Floor_first_color < 0 || data->Floor_first_color > 255)
		|| (data->Floor_second_color < 0 || data->Floor_second_color > 255)
		|| (data->Floor_third_color < 0 || data->Floor_third_color > 255))
		return(1);
	return (0);
}

int	ceiling_format_validation(t_data *data)
{
	int		j;
	char	*s2;

	j = -1;
	s2 = data->map[data->line_Ceiling];
	while (++j <= data->index_Ceiling)
		s2++;
	data->Ceiling_first_color = ft_atoi(s2);
	s2 = ft_strchr(s2, ',');
	s2++;
	data->Ceiling_second_color = ft_atoi(s2);
	s2 = ft_strchr(s2, ',');
	s2++;
	data->Ceiling_third_color = ft_atoi(s2);
	if ((data->Ceiling_first_color < 0 || data->Ceiling_first_color > 255)
		|| (data->Ceiling_second_color < 0 || data->Ceiling_second_color > 255)
		|| (data->Ceiling_third_color < 0 || data->Ceiling_third_color > 255))
		return(1);
	return (0);
}

int		floor_ceiling_validation(t_data *data)
{
	if (floor_ceiling_found(data))
		return(err("error in search of Floor and Ceiling"));
	if (floor_format_validation(data))
		return(err("Floor :\t\t\t\t\033[31mColor KO\033[0m\n"));
	else
		ft_printf("Floor :\t\t\t\t\033[32mColor OK\033[0m\n");
	if (ceiling_format_validation(data))
		return(err("Ceiling :\t\t\t\033[31mColor KO\033[0m\n\n"));
	else
		ft_printf("Ceiling :\t\t\t\033[32mColor OK\033[0m\n\n");
	return (0);
}
