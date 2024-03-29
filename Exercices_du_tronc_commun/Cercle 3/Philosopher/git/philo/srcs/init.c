/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:06:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/03 14:34:20 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_init_data(t_data *data, char **argv, int argc)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->nb_eat_min = -1;
	if (argc == 6)
		data->nb_eat_min = ft_atoi(argv[5]);
	data->all_ate = 0;
	data->death = 0;
}

int	ft_init_philo(t_data *data)
{
	int	i;

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

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&(data->mutex_forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(data->print), NULL))
		return (1);
	if (pthread_mutex_init(&(data->check_death), NULL))
		return (1);
	if (pthread_mutex_init(&(data->meal_check), NULL))
		return (1);
	return (0);
}
