/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:32:47 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/29 17:00:21 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		main(int ac, char **av)
{
	t_data	*data;

	if (ac != 5 && ac != 6)
		printf("Error : Wrong number of args\n");
	else if (!ft_check_args(av))
		printf("Error : Wrong format of args\n");
	else
	{
		data = (t_data *)malloc(sizeof(t_data));
		ft_init_data(data, av);
		init_philos(data);
		init_semaphore(data);
		launcher(data);
	}
	return (0);
}
