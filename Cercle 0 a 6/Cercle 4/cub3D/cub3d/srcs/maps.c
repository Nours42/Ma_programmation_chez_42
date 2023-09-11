/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:54:28 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/11 13:01:34 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	color_verif(char *s)
{
	int	i;

	if (s)
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

int	fc_validation(char *s, int i)
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

int	cub_validation(t_map	*cub)
{
	if (ft_strncmp(cub->map[0], "NO", 2) != 0
		|| ft_strncmp(cub->map[1], "SO", 2) != 0
		|| ft_strncmp(cub->map[2], "WE", 2) != 0
		|| ft_strncmp(cub->map[3], "EA", 2) != 0)
		return (err_map("Textures"));
	else
		ft_printf("Textures :\t\t\t\033[32mOK\033[0m\n");
	if (fc_validation(cub->map[4], 1))
		return (titre_err(" FLOOR manquant "));
	else
		ft_printf("Floor :\t\t\t\t\033[32mOK\033[0m\n");
	if (fc_validation(cub->map[5], 2))
		return (titre_err(" CEILING manquant "));
	else
		ft_printf("Ceiling :\t\t\t\033[32mOK\033[0m\n");
	if (map_validation(cub))
		return (1);
	else
		ft_printf("structure de la map :\t\t\033[32mOK\033[0m\n\n");
	return (0);
}

int	ft_check(int argc, char **argv, t_map *cub)
{
	int		fd;
	int		i;
	char	*str;

	if (argc > 1)
	{
		if (ft_cub(argv[1]))
			return (1);
		cub->map = (char **)malloc(sizeof(char *) * 100);
		fd = open(argv[1], O_RDONLY);
		i = -1;
		str = ft_get_next_line(fd);
		if (!str)
			return (err("erreur dans l'ouverture de la map\n"));
		while (str)
		{
			cub->map[++i] = ft_strdup(str);
			free(str);
			str = ft_get_next_line(fd);
		}
		return (ft_check2(cub));
	}
	else
		return (err("ou est la carte ?\n"));
	return (0);
}

int	ft_check2(t_map *cub)
{
	ft_printf("\e[1;1H\e[2J");
	titre(" TEST DE LA MAP ");
	if (cub_validation(cub))
		return (titre_err(" MAP : KO "));
	else
		titre(" MAP : OK ");
	player_coordonate(cub);
	titre(" TEST PERSO ");
	if (only_one_player(cub))
		return (titre_err(" too perso "));
	else
		ft_printf("Personnage : 1\t\t\t\033[32mOK\033[0m\n");
	if (player_can_moove(cub))
		return (titre_err(" pers moove "));
	else
	{
		ft_printf("Personnage : peut bouger\t\033[32mOK\033[0m\n\n");
		titre(" PERSO : OK ");
	}
	free(cub);
	return (0);
}
