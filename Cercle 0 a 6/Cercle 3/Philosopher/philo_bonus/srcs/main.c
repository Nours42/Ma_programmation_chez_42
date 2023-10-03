/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:32:47 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/03 10:48:23 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		printf("Error : Wrong number of args\n");
	else if (!ft_check_args(argv))
		printf("Error : Wrong format of args\n");
	else
	{
		ft_init_data(&data, argv, argc);
		ft_init_philo(&data);
		init_semaphore(&data);
		ft_create_threads(&data);
	}
	return (0);
}
