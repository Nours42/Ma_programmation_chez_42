/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:38:27 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/27 15:45:56 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	search_textures(t_data *data, char *texture)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (ft_strncmp(data->map[i], texture, 2) == 0)
			return (i);
		i++;
	}
	return (-1);
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
	else
	{
		data->no_texture = go_3_cut_end(data->map[data->no_texture_index]);
		data->so_texture = go_3_cut_end(data->map[data->so_texture_index]);
		data->we_texture = go_3_cut_end(data->map[data->we_texture_index]);
		data->ea_texture = go_3_cut_end(data->map[data->ea_texture_index]);
		ft_printf("Textures :\t\t\t\033[32mOK\033[0m\n");
	}
	return (0);
}

char	*go_3_cut_end(char *s)
{
	char	*res;
	size_t	length;
	size_t	i;
	int		j;

	i = 3;
	j = 3;
	length = ft_strlen(s) - 1;
	res = malloc(sizeof(char) * (length - i + 1));
	while (s[i] == ' ' || s[i] == '\t')
	{
		j++;
		i++;
	}
	while (i < length)
	{
		res[i - j] = s[i];
		i++;
	}
	res[i - j] = '\0';
	return (res);
}
