/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:01:50 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/03 10:48:05 by sdestann         ###   ########.fr       */
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
		sem_wait((data->meal_check));
		if (ft_timestamp() - philo[i].last_meal >= data->time_to_die)
		{
			ft_print_action(data, philo->id, "died 💀", "\e[1;36m");
			sem_wait(data->check_death);
			data->death = 1;
			sem_post(data->check_death);
		}
		sem_post((data->meal_check));
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
		sem_wait(data->check_death);
		if (data->death == 1)
		{
			sem_post(data->check_death);
			break ;
		}
		sem_post(data->check_death);
	}
}

void	exit_launcher(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_join(data->philo[i].thread_id, NULL);
	sem_close(data->forks);
	sem_close(data->print);
	sem_close(data->meal_check);
	sem_close(data->check_death);
	sem_unlink("/philo_forks");
	sem_unlink("/philo_print");
	sem_unlink("/philo_mealcheck");
	sem_unlink("/philo_checkdeath");
}
