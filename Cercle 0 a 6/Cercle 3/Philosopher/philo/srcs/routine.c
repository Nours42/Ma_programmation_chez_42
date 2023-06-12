/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:11:19 by sdestann          #+#    #+#             */
/*   Updated: 2023/06/12 14:24:39 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_putdown_fork(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&(data->mutex_forks[philo->left_fork]));
	data->fork_available[philo->left_fork] = 1;
	philo->fork1 = 0;
	pthread_mutex_unlock(&(data->mutex_forks[philo->left_fork]));
	pthread_mutex_lock(&(data->mutex_forks[philo->right_fork]));
	data->fork_available[philo->right_fork] = 1;
	philo->fork2 = 0;
	pthread_mutex_unlock(&(data->mutex_forks[philo->right_fork]));
}

void	ft_take_forks(t_philo *philo, t_data *data)
{
	if ((philo->fork1 + philo->fork2 != 2))
	{
		pthread_mutex_lock(&(data->mutex_forks[philo->left_fork]));
		if (!philo->fork1 && data->fork_available[philo->left_fork] == 1)
		{
			data->fork_available[philo->left_fork] = 0;
			philo->fork1 = 1;
			ft_print_action(data, philo->id, "has taken a fork 🍴", "\e[1;31m");
		}
		pthread_mutex_unlock(&(data->mutex_forks[philo->left_fork]));
		pthread_mutex_lock(&(data->mutex_forks[philo->right_fork]));
		if (!philo->fork2 && data->fork_available[philo->right_fork] == 1)
		{
			data->fork_available[philo->right_fork] = 0;
			philo->fork2 = 1;
			ft_print_action(data, philo->id, "has taken a fork 🍴", "\e[1;32m");
		}
		pthread_mutex_unlock(&(data->mutex_forks[philo->right_fork]));
	}
	usleep(10);
}

void	ft_eat(t_philo *philo, t_data *data)
{
	if (philo->fork1 + philo->fork2 == 2)
	{
		philo->nb_eat++;
		if (data->nb_eat_min != -1 && (philo->nb_eat == data->nb_eat_min))
			data->all_ate++;
		ft_print_action(data, philo->id, "is eating 🍝", "\e[1;33m");
		ft_sleep(data->time_to_eat);
		pthread_mutex_lock(&(data->meal_check));
		philo->last_meal = ft_timestamp();
		pthread_mutex_unlock(&(data->meal_check));
		ft_putdown_fork(philo, data);
		if (data->all_ate != data->nb_philo)
		{
			ft_print_action(data, philo->id, "is sleeping 💤", "\e[1;34m");
			ft_sleep(data->time_to_sleep);
			if (data->all_ate != data->nb_philo)
				ft_print_action(data, philo->id, "is thinking 💡", "\e[1;35m");
		}
	}
}

void	*routine(void *philo_void)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)philo_void;
	data = philo->data;
	if (philo->id % 2 == 0)
		ft_sleep(data->time_to_eat);
	while (!ft_is_dead(data) && (data->nb_eat_min == -1
			|| data->all_ate != data->nb_philo))
	{
		ft_take_forks(philo, data);
		ft_eat(philo, data);
	}
	return (NULL);
}

int	ft_create_threads(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = data->philo;
	while (i < data->nb_philo)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, routine, &(philo[i])))
			return (1);
		pthread_mutex_lock(&(data->meal_check));
		philo[i].last_meal = ft_timestamp();
		pthread_mutex_unlock(&(data->meal_check));
		i++;
	}
	ft_loop_check(data, philo);
	ft_exit_mutex(data);
	return (0);
}
