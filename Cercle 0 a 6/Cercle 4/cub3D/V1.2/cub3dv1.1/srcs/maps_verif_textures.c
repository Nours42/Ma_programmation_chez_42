/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_verif_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:38:27 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/28 16:53:42 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	texture_validation(t_data *data)
{
	data->no_texture_index = search_textures(data, "NO ");
	data->so_texture_index = search_textures(data, "SO ");
	data->we_texture_index = search_textures(data, "WE ");
	data->ea_texture_index = search_textures(data, "EA ");
	if (data->no_texture_index == -1 || data->so_texture_index == -1
		|| data->we_texture_index == -1 || data->ea_texture_index == -1)
		ft_exit_failure(data, 1, "Texture manquante", \
		"MAP : 1\t\t\t\033[32mKO\033[0m\n");
	else if (data->no_texture_index == -2 || data->so_texture_index == -2
		|| data->we_texture_index == -2 || data->ea_texture_index == -2)
		ft_exit_failure(data, 1, "Texture en double", \
		"MAP : 1\t\t\t\033[32mKO\033[0m\n");
	else if (data->no_texture_index == -3 || data->so_texture_index == -3
		|| data->we_texture_index == -3 || data->ea_texture_index == -3)
		ft_exit_failure(data, 1, "Texture non xpm", \
		"MAP : 1\t\t\t\033[32mKO\033[0m\n");
	else
	{
		data->no_texture = texture_file(data->map[data->no_texture_index]);
		if (data->no_texture == NULL)
			ft_exit_failure(data, 1, "Erreur dans la creation de no_texture", \
			"MAP : 1\t\t\t\033[32mKO\033[0m\n");
		data->so_texture = texture_file(data->map[data->so_texture_index]);
		if (data->so_texture == NULL)
		{
			ft_clean_textures(data, 1);
			ft_exit_failure(data, 1, "Erreur dans la creation de so_texture", \
			"MAP : 1\t\t\t\033[32mKO\033[0m\n");
		}
		data->we_texture = texture_file(data->map[data->we_texture_index]);
		if (data->we_texture == NULL)
		{
			ft_clean_textures(data, 1);
			ft_clean_textures(data, 2);
			ft_exit_failure(data, 1, "Erreur dans la creation de we_texture", \
			"MAP : 1\t\t\t\033[32mKO\033[0m\n");
		}
		data->ea_texture = texture_file(data->map[data->ea_texture_index]);
		if (data->ea_texture == NULL)
		{
			ft_clean_textures(data, 1);
			ft_clean_textures(data, 2);
			ft_clean_textures(data, 3);
			ft_exit_failure(data, 1, "Erreur dans la creation de ea_texture", \
			"MAP : 1\t\t\t\033[32mKO\033[0m\n");
		}
		ft_printf("Textures :\t\t\t\033[32mOK\033[0m\n");
	}
	return (0);
}

int	search_textures(t_data *data, char *texture)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (data->map[i])
	{
		if (ft_strncmp(data->map[i], texture, 3) == 0)
		{
			if (search_xpm(data->map[i]))
				return (-3);
			if (j == -1)
				j = i;
			else
				return (-2);
		}
		i++;
	}
	return (j);
}

int	search_xpm(char *s)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	cpy = (char *)malloc(sizeof(char) * 4 + 1);
	if (!cpy)
		return (1);
	while (j < 4)
	{
		cpy[j] = s[i - (5 - j)];
		j++;
	}
	if (cpy [0] == '.' && cpy[1] == 'x' && cpy[2] == 'p'
		&& cpy[3] == 'm')
	{
		free(cpy);
		return (0);
	}
	free(cpy);
	return (1);
}

char	*texture_file(char *s)
{
	int		length;
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	s += 3;
	while (s[j] == ' ' || s[j] == '\t')
		j++;
	length = ft_strlen(s);
	res = (char *)malloc((sizeof(char) * length) + 1);
	if (!res)
		return (NULL);
	while (s[i + j] != '\n')
	{
		res[i] = s[i + j];
		i++;
	}
	res[i] = '\0';
	return (res);
}
