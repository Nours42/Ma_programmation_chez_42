/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:11:19 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/29 16:58:08 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_take_forks(t_philo *philo, t_data *data)
{
	sem_wait(data->forks);
	ft_print_action(data, philo->id, "has taken a fork 🍴", "\e[1;31m");
	sem_post(data->forks);
	sem_wait(data->forks);
	ft_print_action(data, philo->id, "has taken a fork 🍴", "\e[1;32m");
	sem_post(data->forks);
}

void	ft_eat(t_philo *philo, t_data *data)
{
	philo->nb_eat++;
	if (data->nb_eat_min != -1 && (philo->nb_eat == data->nb_eat_min))
		data->all_ate++;
	ft_print_action(data, philo->id, "is eating 🍝", "\e[1;33m");
	ft_sleep(data->time_to_eat);
	sem_wait(data->meal_check);
	philo->last_meal = ft_timestamp();
	sem_post(data->meal_check);
	if (data->all_ate != data->nb_philo)
	{
		ft_print_action(data, philo->id, "is sleeping 💤", "\e[1;34m");
		ft_sleep(data->time_to_sleep);
		if (data->all_ate != data->nb_philo)
			ft_print_action(data, philo->id, "is thinking 💡", "\e[1;35m");
	}
}

void	routine(void *void_phil)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)void_phil;
	data = philo->data;
	if (philo->id % 2)
		usleep(15000);
	philo->last_meal = ft_timestamp();
	pthread_create(&(philo->death_check), NULL, ft_check_die, void_phil);
	
	while (!(data->dieded))
	{
		ft_take_forks(philo, data);
		if (philo->nb_eat >= data->nb_eat_min && data->nb_eat_min != -1)
			break ;
		ft_print_action(data, philo->id, "is sleeping", "\e[1;34m");
		ft_sleep(data->time_to_sleep);
		ft_print_action(data, philo->id, "is thinking", "\e[1;35m");
	}
	pthread_join(philo->death_check, NULL);
	if (data->dieded)
		exit(1);
	exit(0);
}

void	exit_launcher(t_data *data)
{
	int	i;
	int	ret;

	i = 0;
	while (i < data->nb_philo)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = -1;
			while (++i < data->nb_philo)
				kill(data->philo[i].proc_id, 15);
			break ;
		}
		i++;
	}
	sem_close(data->forks);
	sem_close(data->writing);
	sem_close(data->meal_check);
	sem_unlink("/philo_forks");
	sem_unlink("/philo_write");
	sem_unlink("/philo_mealcheck");
}

int		launcher(t_data *data)
{
	int				i;
	t_philo	*phi;

	i = -1;
	phi = data->philo;
	data->first_timestamp = ft_timestamp();
	while (++i < data->nb_philo)
	{
		phi[i].proc_id = fork();
		if (phi[i].proc_id < 0)
			return (1);
		if (phi[i].proc_id == 0)
			routine(&(phi[i]));
		usleep(100);
	}
	exit_launcher(data);
	return (0);
}
