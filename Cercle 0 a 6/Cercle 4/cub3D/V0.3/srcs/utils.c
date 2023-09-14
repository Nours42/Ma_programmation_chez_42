/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:20:10 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/13 16:21:47 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*make_color_hex(int n)
{
	char	*base;
	char	*res;

	res = (char *)malloc(sizeof(char) * 3);
	
	base = "0123456789ABCDEF";
	res[0] = base[n / 16];
	res[1] = base[n % 16];
	res[2] = 0;
	return (res);
}

char	*get_map_color(t_data *data)
{
	char	*color_map_hex;
	char	*res;
	int		i;
	int		j;
	int		k;

	j = 1;
	res = 0;
	color_map_hex = ft_strdup(data->map->map[4]);
	color_map_hex += 2;
	while (j < 4)
	{
		i = ft_atoi(color_map_hex);
		if (i < 10)
			k = 2;
		else if (i < 100)
			k = 3;
		else
			k = 4;
		if (j == 1)
			res = ft_strjoin("0x00", make_color_hex(i));
		else
			res = ft_strjoin(res, make_color_hex(i));
		color_map_hex += k;
		j++;
	}
	return (res);
}
