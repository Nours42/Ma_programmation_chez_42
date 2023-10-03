/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:11:19 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/03 09:20:47 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	philo_eats(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	sem_wait(data->meal_check);
	sem_wait(data->forks);
	ft_print_action(data, philo->id, "has taken a fork 🍴", "\e[1;31m");
	sem_wait(data->forks);
	ft_print_action(data, philo->id, "has taken a fork 🍴", "\e[1;32m");
	sem_post(data->meal_check);
	sem_wait(data->meal_check);
	ft_print_action(data, philo->id, "is eating 🍝", "\e[1;33m");
	ft_sleep(data->time_to_eat, data);
	philo->nb_eat++;
	philo->last_meal = ft_timestamp();
	sem_post(data->meal_check);
	sem_post(data->forks);
	sem_post(data->forks);
}

static int	ft_is_dead(t_data *data)
{
	sem_wait(data->meal_check);
	if (data->death == 1)
	{
		sem_post(data->meal_check);
		return (1);
	}
	else
	{
		sem_post(data->meal_check);
		return (0);
	}
}

static void	*p_process(void *void_phil)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)void_phil;
	data = philo->data;
	if (philo->id % 2)
		usleep(200);
	while (!ft_is_dead(data))
	{
		philo_eats(philo);
		if (data->all_ate)
			break ;
		sem_wait(data->meal_check);
		ft_print_action(data, philo->id, "is sleeping 💤", "\e[1;34m");
		ft_sleep(data->time_to_sleep, data);
		ft_print_action(data, philo->id, "is thinking 💡", "\e[1;35m");
		sem_post(data->meal_check);
	}
	exit(0);
}



static void	*death_checker(t_data *data, t_philo *philo, int i)
{
	while (!(data->all_ate))
	{
		i = -1;
		while (++i < data->nb_philo && !(data->death))
		{
			sem_wait(data->meal_check);
			if (time_diff(philo->last_meal, ft_timestamp()) > data->time_to_die)
			{
				ft_print_action(data, philo->id, "died 💀", "\e[1;36m");
				data->death = 1;
			}
			sem_post(data->meal_check);
			usleep(100);
		}
		if (data->death)
			break ;
		i = 0;
		while (data->nb_eat_min != -1 && i < data->nb_philo && philo[i].nb_eat
			>= data->nb_eat_min)
			i++;
		if (i == data->nb_philo)
			data->all_ate = 1;
	}
	return (NULL);
}

int	launcher(t_data *data)
{
	int		i;
	t_philo	*phi;

	i = -1;
	phi = data->philo;
	data->start_time = ft_timestamp();
	while (++i < data->nb_philo)
	{
		if (pthread_create(&(phi[i].proc_id), NULL, p_process, &(phi[i])))
			return (1);
		sem_wait(data->meal_check);
		phi[i].last_meal = ft_timestamp();
		sem_post(data->meal_check);
	}
	death_checker(data, data->philo, -1);
	exit_launcher(data, phi);
	return (0);
}
