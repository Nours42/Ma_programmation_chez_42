/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:49:17 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/02 09:55:43 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static inline int	is_repeat(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static inline int	isnum(char	*num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static inline void	error_gest(char **argv)
{
	int		i;
	long	temp;

	i = 1;
	while (argv[i])
	{
		temp = ft_atoi(argv[i]);
		if (!isnum(argv[i]))
			error_msg("Error - one of parameters is not a number");
		if (ft_strlen(argv[i]) == 0)
			error_msg("Error - one of parameters is a \"\"");
		temp = ft_atol(argv[i]);
		if (temp < -2147483648 || temp > 2147483647)
			error_msg("Error - at minimum one of parameters is too big");
		if (is_repeat(temp, argv, i))
			error_msg("Error - duplicate numeric parameters");
		i++;
	}
}

void	check_args(int argc, char **argv)
{
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!*argv)
			return ;
	}
	error_gest(argv);
	if (argc == 2)
		ft_free(argv);
}
