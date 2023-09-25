/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:54:28 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/25 12:59:02 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check(int argc, char **argv, t_data *data)
{
	if (argc == 2)
	{
		ft_create_map(data, argv);
		if (ft_test_map(data))
			return (1);
		else if (ft_test_perso(data))
			return (1);
	}
	else
		return (err("ou est la carte ?\n"));
	return (0);
}

int	ft_create_map(t_data *data, char **argv)
{
	int		i;
	int		fd;
	char	*str;

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
	return (0);
}

int	ft_test_map(t_data *data)
{
	ft_printf("\e[1;1H\e[2J");
	titre(" TEST DE LA MAP ");
	if (texture_validation(data) || floor_ceiling_validation(data))
		return (titre_err(" MAP : KO "));
	else
		titre(" MAP : OK ");
	fill_fc_color(data);
	find_start_end_of_map(data);
	resize_map(data);
	if (go_around_the_walls(data))
		return (err("mur d'enceinte :\t\t\033[31mKO\033[0m\n"));
	else
		ft_printf("mur d'enceinte :\t\t\033[32mOK\033[0m\n");
	ft_restore_map(data);
	return (0);
}

int	ft_test_perso(t_data *data)
{
	player_coordonate(data, data->Map_first_line, 0);
	titre(" TEST PERSO ");
	if (only_one_player(data))
		return (titre_err(" too or not perso "));
	else
		ft_printf("Personnage : 1\t\t\t\033[32mOK\033[0m\n");
	return (0);
}

void	ft_restore_map(t_data *data)
{
	int	i;
	int	j;

	i = data->Map_first_line;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '2'
				|| data->map[i][j] == '3'
				|| data->map[i][j] == '4')
			{
				data->map[i][j] = '1';
			}
			j++;
		}
		i++;
	}
}
