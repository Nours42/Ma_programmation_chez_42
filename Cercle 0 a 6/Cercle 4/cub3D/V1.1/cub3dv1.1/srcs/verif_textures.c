/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:38:27 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/27 19:45:44 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	search_textures(t_data *data, char *texture)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (data->map[i])
	{
		if (ft_strncmp(data->map[i], texture, 2) == 0)
		{
			if (j == -1)
				j = i;
			else
				return (-2);
		}
		i++;
	}
	return (j);
}

char	*texture_file(char *s)
{
	int	length;
	int	i;
	int	j;
	char *res;

	i = 0;
	j = 0;
	s += 3;
	while (s[j] == ' ' || s[j] == '\t')
		j++;
	length = ft_strlen(s);
	res = (char *)malloc((sizeof(char) * length) + 1);
	while (s[i + j] != '\n')
	{
		res[i] = s[i + j];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	texture_validation(t_data *data)
{
	data->no_texture_index = search_textures(data, "NO");
	data->so_texture_index = search_textures(data, "SO");
	data->we_texture_index = search_textures(data, "WE");
	data->ea_texture_index = search_textures(data, "EA");
	if (data->no_texture_index == -1 || data->so_texture_index == -1
		|| data->we_texture_index == -1 || data->ea_texture_index == -1)
		return (err_map("Texture manquante"));
	else if (data->no_texture_index == -2 || data->so_texture_index == -2
		|| data->we_texture_index == -2 || data->ea_texture_index == -2)
		return (err_map("Texture en double"));
	else
	{
		data->no_texture = texture_file(data->map[data->no_texture_index]);
		data->so_texture = texture_file(data->map[data->so_texture_index]);
		data->we_texture = texture_file(data->map[data->we_texture_index]);
		data->ea_texture = texture_file(data->map[data->ea_texture_index]);
		ft_printf("Textures :\t\t\t\033[32mOK\033[0m\n");
	}
	return (0);
}
