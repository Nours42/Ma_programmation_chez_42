/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:49:18 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/29 22:49:44 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_check_digit(char *argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_overflow(char *argv)
{
	if (ft_atoi(argv) > INT_MAX || ft_atoi(argv) < 0)
		return (0);
	return (1);
}

int	ft_check_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_check_digit(argv[i]))
			return (4);
		else if (!ft_check_overflow(argv[i]))
			return (3);
		i++;
	}
	return (0);
}
