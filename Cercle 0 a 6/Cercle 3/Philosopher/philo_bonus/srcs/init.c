/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:06:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/29 16:04:45 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_init_data(t_data *data, char **argv)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->time_death = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->nb_eat_min = -1;
	if (ac == 6)
		data->nb_eat_min = ft_atoi(av[5]);
	data->all_ate = 0;
	data->death = 0;
	return (0);
}

int	init_philos(t_data *data)
{
	int i;

	i = 0;
	data->start_time = ft_timestamp();
	while (i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].nb_eat = 0;
		data->philo[i].last_meal = 0;
		data->philo[i].fork1 = 0;
		data->philo[i].fork2 = 0;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = (i + 1) % data->nb_philo;
		data->philo[i].data = data;
		data->fork_available[i] = 1;
		i++;
	}
	return (0);
}

int	init_semaphore(t_data *data)
{
	sem_unlink("/philo_forks");
	sem_unlink("/philo_write");
	sem_unlink("/philo_mealcheck");
	data->forks = sem_open("/philo_forks", O_CREAT, S_IRWXU, data->nb_philo);
	data->writing = sem_open("/philo_write", O_CREAT, S_IRWXU, 1);
	data->meal_check = sem_open("/philo_mealcheck", O_CREAT, S_IRWXU, 1);
	return (0);
}



