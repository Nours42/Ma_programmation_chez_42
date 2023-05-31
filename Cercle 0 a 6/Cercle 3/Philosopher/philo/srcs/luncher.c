/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:11:19 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/31 17:11:26 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_eats(t_philo *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	pthread_mutex_lock(&(rules->forks[philo->left_fork_id]));
	action_print(rules, philo->id, "\e[1;34mhas taken a fork on his \
		left 🍴\e[0m");
	pthread_mutex_lock(&(rules->forks[philo->right_fork_id]));
	action_print(rules, philo->id, "\e[1;33mhas taken a fork on his \
		right 🍴\e[0m");
	pthread_mutex_lock(&(rules->meal_check));
	if (philo->nb_ate < rules->nb_eat)
	{
		action_print(rules, philo->id, "\e[1;32mis eating 🍝\e[0m");
		philo->time_of_last_meal = timestamp();
		(philo->nb_ate)++;
	}
	pthread_mutex_unlock(&(rules->meal_check));
	smart_sleep(rules->eat_time, rules);
	pthread_mutex_unlock(&(rules->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(rules->forks[philo->right_fork_id]));
}

void	*p_thread(void *void_philo)
{
	int				i;
	t_philo			*philo;
	t_rules			*rules;

	i = 0;
	philo = (t_philo *)void_philo;
	rules = philo->rules;
	while (!(rules->already_died))
	{
		if (philo->id % 2)
			usleep(6000);
		philo_eats(philo);
		if (rules->all_ate)
			break ;
		action_print(rules, philo->id, "\e[1;35mis sleeping 💤\e[0m");
		smart_sleep(rules->sleep_time, rules);
		action_print(rules, philo->id, "\e[1;36mis thinking 💡\e[0m");
		i++;
	}
	return (NULL);
}

void	exit_launcher(t_rules *rules, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < rules->nb_of_phi)
		pthread_join(philos[i].thread_id, NULL);
	i = -1;
	while (++i < rules->nb_of_phi)
		pthread_mutex_destroy(&(rules->forks[i]));
	pthread_mutex_destroy(&(rules->writing));
}

void	death_checker(t_rules *r, t_philo *p)
{
	int	i;

	
	while (1)
	{
		pthread_mutex_lock(&(r->meal_check));
		if ((r->all_ate))
		{
			pthread_mutex_unlock(&(r->meal_check));
			break;
		}
		i = -1;
		while (++i < r->nb_of_phi && !(r->already_died))
		{
			if (time_diff(p[i].time_of_last_meal, timestamp()) > r->die_time)
			{
				action_print(r, i, "\e[1;31mdieded 💀\e[0m");
				r->already_died = 1;
			}
			usleep(100);
		}
		if (r->already_died)
		{
			pthread_mutex_unlock(&(r->meal_check));
			break ;
		}
		i = 0;
		
		while (r->nb_eat != -1 && i < r->nb_of_phi && p[i].nb_ate == r->nb_eat)
			i++;
		if (i == r->nb_of_phi)
			r->all_ate = 1;
		pthread_mutex_unlock(&(r->meal_check));
	}
	
}

int	ready_to_crumble(t_rules *rules)
{
	int				i;
	t_philo			*phi;

	i = 0;
	phi = rules->philo;
	rules->first_timestamp = timestamp();
	while (i < rules->nb_of_phi)
	{
		if (pthread_create(&(phi[i].thread_id), NULL, p_thread, &(phi[i])))
			return (1);
		phi[i].time_of_last_meal = timestamp();
		i++;
	}
	death_checker(rules, rules->philo);
	exit_launcher(rules, phi);
	return (0);
}
