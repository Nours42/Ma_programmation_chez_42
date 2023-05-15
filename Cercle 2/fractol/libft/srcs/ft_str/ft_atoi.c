/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:07:24 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/24 12:08:26 by sdestann         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	size_t	res;
	int		i;
	int		sign;

	sign = 1;
	res = 0;
	i = ft_atoi_helper(str, &sign);
	while ((str[i]) >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		++i;
		if ((sign > 0) && (res > 2147483647))
			return (-1);
		if ((sign < 0) && (res > 2147483648))
			return (0);
	}
	return ((int) res * sign);
}
