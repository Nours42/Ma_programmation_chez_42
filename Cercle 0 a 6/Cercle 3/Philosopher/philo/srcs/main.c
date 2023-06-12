/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:32:47 by sdestann          #+#    #+#             */
/*   Updated: 2023/06/12 14:15:32 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		printf("Error : Wrong number of args\n");
	else if (!ft_check_args(av))
		printf("Error : Wrong format of args\n");
	else
	{
		ft_init_data(&data, av, ac);
		ft_init_philo(&data);
		ft_init_mutex(&data);
		ft_create_threads(&data);
	}
	return (0);
}
