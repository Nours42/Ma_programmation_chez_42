/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:01:50 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/03 14:30:01 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_check_die(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo && !ft_is_dead(data)
		&& (data->all_ate != data->nb_philo))
	{
		pthread_mutex_lock(&(data->meal_check));
		if (ft_timestamp() - philo[i].last_meal >= data->time_to_die)
		{
			ft_print_action(data, philo->id, "died 💀", "\e[1;36m");
			pthread_mutex_lock(&data->check_death);
			data->death = 1;
			pthread_mutex_unlock(&data->check_death);
		}
		pthread_mutex_unlock(&(data->meal_check));
		i++;
	}
}

void	ft_loop_check(t_data *data, t_philo *philo)
{
	while (1)
	{
		ft_check_die(data, philo);
		if (data->all_ate == data->nb_philo)
		{
			break ;
		}
		pthread_mutex_lock(&data->check_death);
		if (data->death == 1)
		{
			pthread_mutex_unlock(&data->check_death);
			break ;
		}
		pthread_mutex_unlock(&data->check_death);
	}
}

void	ft_exit_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philo[i].thread_id, NULL);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&(data->mutex_forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(data->print));
	pthread_mutex_destroy(&(data->meal_check));
	pthread_mutex_destroy(&(data->check_death));
}
