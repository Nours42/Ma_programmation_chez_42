/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:54:28 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/23 21:12:53 by nours42          ###   ########.fr       */
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
			// ft_printf("avant dup : %s", str);
			data->map[i++] = ft_strdup(str);
			// ft_printf("apres dup : %s", str);
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
	char	*res;
	int		j;
	size_t	len;
	
	j = data->Map_first_line - 1;
	while (data->map[++j])
	{
		len = ft_strlen(data->map[j]);
		if (len < data->size_max)
		{
			res = data->map[j];
			data->map[j] = ft_realloc_space(res, len - 1, data->size_max + 1);
		}
	}
}

void    *ft_realloc_space(void *ptr, size_t original_size, size_t new_size)
{
	void	*new_memblock;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size <= original_size)
		return (ptr);
	new_memblock = malloc(new_size);
	if (ptr)
	{
		if (!new_memblock)
			return (NULL);
		ft_memcpy(new_memblock, ptr, original_size);
		ft_memset2(new_memblock + original_size, ' ', new_size - original_size);
		free(ptr);
	}
	return (new_memblock);
}

void	*ft_memset2(void *b, int c, size_t len)
{
	char	*str;

	str = b;
	len--;
	while (len)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	c = 0;
	*str = (unsigned char)c;
	return (b);
}