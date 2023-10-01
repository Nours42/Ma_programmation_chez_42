/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:06:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/01 13:02:19 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_semaphore(t_data *data)
{
	sem_unlink("/philo_forks");
	sem_unlink("/philo_write");
	sem_unlink("/philo_mealcheck");
	data->forks = sem_open("/philo_forks", O_CREAT, S_IRWXU, data->nb_philo);
	data->writing = sem_open("/philo_write", O_CREAT, S_IRWXU, 1);
	data->meal_check = sem_open("/philo_mealcheck", O_CREAT, S_IRWXU, 1);
	if (data->forks == SEM_FAILED || data->writing == SEM_FAILED
		|| data->meal_check == SEM_FAILED)
		return (1);
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = data->nb_philo;
	while (--i >= 0)
	{
		data->philo[i].id = i;
		data->philo[i].nb_eat = 0;
		data->philo[i].last_meal = 0;
		data->philo[i].fork1 = 0;
		data->philo[i].fork2 = 0;
		data->philo[i].data = data;
	}
	return (0);
}

int	init_all(t_data *data, char **argv)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->death = 0;
	data->forks_available = data->nb_philo;
	if (data->nb_philo < 2 || data->time_to_die < 0 || data->time_to_eat < 0
		|| data->time_to_sleep < 0 || data->nb_philo > 250)
		return (1);
	if (argv[5])
	{
		data->nb_eat_min = ft_atoi(argv[5]);
		if (data->nb_eat_min <= 0)
			return (1);
	}
	else
		data->nb_eat_min = -1;
	if (data->nb_eat_min == 1)
		data->nb_eat_min++;
	if (init_semaphore(data))
		return (2);
	init_philo(data);
	return (0);
}
