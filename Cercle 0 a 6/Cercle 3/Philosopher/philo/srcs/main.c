/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:32:47 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/29 20:42:38 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **argv)
{
	t_data	data;

	if (argc!= 5 && argc!= 6)
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
