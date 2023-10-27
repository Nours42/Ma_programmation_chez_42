/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:49:18 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/03 10:34:22 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_check_digit(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_oveflow(char *argv)
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
		if (!ft_check_digit(argv[i]) || !ft_check_oveflow(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
