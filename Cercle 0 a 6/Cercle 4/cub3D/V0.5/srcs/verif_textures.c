/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:38:27 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/19 15:39:50 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	search_textures(t_data *data, char *texture)
{
	int i;

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
	data->NO_texture = search_textures(data, "NO");
	data->SO_texture = search_textures(data, "SO");
	data->WE_texture = search_textures(data, "WE");
	data->EA_texture = search_textures(data, "EA");
	if (data->NO_texture == -1 || data->SO_texture == -1
		|| data->WE_texture == -1 || data->EA_texture == -1)
		return (err_map("Texture manquante"));
	else
		ft_printf("Textures :\t\t\t\033[32mOK\033[0m\n");
	return (0);
}
