/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:49:18 by sdestann          #+#    #+#             */
/*   Updated: 2023/06/12 14:04:32 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_check_digit(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_oveflow(char *av)
{
	if (ft_atoi(av) > INT_MAX || ft_atoi(av) < 0)
		return (0);
	return (1);
}

int	ft_check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!ft_check_digit(av[i]) || !ft_check_oveflow(av[i]))
			return (0);
		i++;
	}
	return (1);
}
