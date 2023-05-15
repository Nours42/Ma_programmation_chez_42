/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:14:34 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/25 11:12:34 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_atoi_helper(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '-')
	{
		*sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	return (i);
}

double	ft_atof(const char *str)
{
	double	res;
	int		i;
	int		k;
	double	mantissa;

	i = 0;
	res = fabs((double)ft_atoi(str));
	while (str[i] && str[i] != '.')
		++i;
	if (str[i] != '.')
		return (res);
	mantissa = 0.0;
	if (str[++i])
	{
		k = 0;
		while (str[i] && k < 17)
			mantissa += (str[i++] - '0') / pow(10, ++k);
		res += mantissa;
		ft_atoi_helper(str, &i);
		if (i < 0)
			res = -res;
	}
	return (res);
}
