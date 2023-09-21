/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:20:10 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/21 16:26:50 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(t_data *data, int i)
{
	while (data->map[++i])
		ft_printf("%d :\t%s", i, data->map[i]);
}

int	empty_line(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] == 32 || (c[i] == 9) || (c[i] == 10))
			i++;
		else
			return (0);
	}
	return (1);
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

int	ft_htoi(char *s)
{
	int	i;
	int	c;
	int	n;

	i = 0;
	c = s[i];
	n = 0;
	while (c != '\0')
	{
		n *= 16;
		if (i == 0 && c == '0')
		{
			c = s[++i];
			if (c != 'x' && c != 'X')
				--i;
		}
		else if (c >= '0' && c <= '9')
			n += c - '0';
		else if (c >= 'a' && c <= 'f')
			n += 10 + (c - 'a');
		else if (c >= 'A' && c <= 'F')
			n += 10 + (c - 'A');
		else
			return (n);
		i++;
	}
	return (n);
}

char	*get_map_color(char *s, int l, t_data *data)
{
	char	*color_map_hex;
	char	*res;
	int		i;
	int		j;
	int		k;

	j = 1;
	res = (char *)malloc(sizeof(char) * 11);
	res[0] = '0';
	res[1] = 'x';
	res[2] = '0';
	res[3] = '0';
	res[10] = '\0';
	color_map_hex = data->map[l];
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
		s = make_color_hex(i);
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
		color_map_hex += k;
		free(s);
		j++;
	}
	return (res);
}
