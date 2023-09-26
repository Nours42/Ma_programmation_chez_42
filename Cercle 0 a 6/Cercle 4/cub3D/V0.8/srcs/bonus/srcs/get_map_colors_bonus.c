/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_colors_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:20:10 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/26 12:12:50 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	fill_fc_color(t_data *d)
{
	char	*s;

	s = d->floor_hex_color;
	d->floor_hex_color = get_map_color(s, d->line_floor, d);
	d->color_map_hex_f = ft_htoi(d->floor_hex_color, 0, 0, \
		d->floor_hex_color[0]);
	s = d->ceiling_hex_color;
	d->ceiling_hex_color = get_map_color(s, d->line_ceiling, d);
	d->color_map_hex_c = ft_htoi(d->ceiling_hex_color, 0, 0, \
		d->ceiling_hex_color[0]);
}

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

char	*get_map_color(char *s, int l, t_data *data)
{
	char	*color_map_hex;
	char	*res;
	int		i;
	int		j;

	j = 1;
	res = (char *)malloc(sizeof(char) * 11);
	res = ft_create_res(res);
	color_map_hex = data->map[l];
	color_map_hex += 2;
	while (j < 4)
	{
		i = ft_atoi(color_map_hex);
		s = make_color_hex(i);
		complete_res(res, j, s);
		color_map_hex += get_k(i);
		free(s);
		j++;
	}
	return (res);
}

char	*ft_create_res(char *res)
{
	res[0] = '0';
	res[1] = 'x';
	res[2] = '0';
	res[3] = '0';
	res[10] = '\0';
	return (res);
}

void	complete_res(char *res, int j, char *s)
{
	if (j == 1)
	{
		res[4] = s[0];
		res[5] = s[1];
	}
	if (j == 2)
	{
		res[6] = s[0];
		res[7] = s[1];
	}
	if (j == 3)
	{
		res[8] = s[0];
		res[9] = s[1];
	}
}
