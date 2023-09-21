/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:54:28 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/21 16:23:30 by sdestann         ###   ########.fr       */
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
		data->map = (char **)malloc(sizeof(char *) * 100);
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
