/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:54:28 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/22 15:24:08 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check(int argc, char **argv, t_data *data)
{
	int		fd;
	int		i;
	char	*str;

	if (argc > 1)
	{
		data->map = (char **)malloc(sizeof(char *) * 10000);
		fd = open(argv[1], O_RDONLY);
		i = 0;
		str = ft_get_next_line(fd);
		if (!str)
			return (err("erreur dans l'ouverture de la map\n"));
		while (str)
		{
			data->map[i++] = ft_strdup(str);
			free(str);
			str = ft_get_next_line(fd);
		}
		data->map[i] = 0;
		ft_printf("\e[1;1H\e[2J");
		titre(" TEST DE LA MAP ");
		if (texture_validation(data) || floor_ceiling_validation(data))
			return (titre_err(" MAP : KO "));
		else
			titre(" MAP : OK ");
		find_start_end_of_map(data);
		resize_map(data);
		if (go_around_the_walls(data))
			return (err("mur d'enceinte :\t\t\033[31mKO\033[0m\n"));
		else
			ft_printf("mur d'enceinte :\t\t\033[32mOK\033[0m\n");
		player_coordonate(data);
		titre(" TEST PERSO ");
		if (only_one_player(data))
			return (titre_err(" too or not perso "));
		else
			ft_printf("Personnage : 1\t\t\t\033[32mOK\033[0m\n");
		i = 0;
		while (data->map[i])
		{
			free(data->map[i]);
			data->map[i] = 0;
			i++;
		}
		free(data->map);
	}
	else
		return (err("ou est la carte ?\n"));
	return (0);
}

void	resize_map(t_data *data)
{
	int		i;

	data->size_max = 0;
	i = data->Map_first_line - 1;
	while (data->map[++i])
	{
		if (ft_strlen(data->map[i]) > data->size_max)
			data->size_max = ft_strlen(data->map[i]);
	}
	i = data->Map_first_line - 1;
	add_spaces(data);
}

void	add_spaces(t_data *data)
{
	size_t	i;
	int		j;
	int		len;
	char	*res;

	j = -1;
	while (data->map[++j])
	{
		if (ft_strlen(data->map[j]) < data->size_max)
		{
			i = 0;
			len = data->size_max;
			res = (char *)malloc(sizeof(char) * len);
			while (len)
			{
				res[i] = ' ';
				i++;
				len--;
			}
			i--;
			res[i] = '\n';
			i = ft_strlen(data->map[j]);
			while (i != 0)
			{
				res[i] = data->map[j][i];
				i--;
			}
			free(data->map[j]);
			data->map[j] = res;
		}
	}
}