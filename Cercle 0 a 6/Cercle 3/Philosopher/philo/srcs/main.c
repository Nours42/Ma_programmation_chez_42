/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:32:47 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/31 17:05:18 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_mutex(t_rules *rules)
{
	int	i;

	i = rules->nb_of_phi;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(rules->writing), NULL))
		return (1);
	if (pthread_mutex_init(&(rules->meal_check), NULL))
		return (1);
	return (0);
}

int	init_philo(t_rules *rules)
{
	int	i;

	i = rules->nb_of_phi;
	while (--i >= 0)
	{
		rules->philo[i].id = i;
		rules->philo[i].nb_ate = 0;
		if (i % 2 == 0)
		{
			rules->philo[i].left_fork_id = i;
			rules->philo[i].right_fork_id = (i + 1) % rules->nb_of_phi;
		}
		else
		{
			rules->philo[i].right_fork_id = i;
			rules->philo[i].left_fork_id = (i + 1) % rules->nb_of_phi;
		}
		rules->philo[i].time_of_last_meal = 0;
		rules->philo[i].rules = rules;
	}
	return (0);
}

int	init_all(t_rules *rules, char **argv)
{
	int	nb_rules;

	rules->nb_of_phi = ft_atoi(argv[1]);
	rules->die_time = ft_atoi(argv[2]);
	rules->eat_time = ft_atoi(argv[3]);
	rules->sleep_time = ft_atoi(argv[4]);
	if (rules->nb_of_phi < 2 || rules->die_time < 0 || rules->eat_time < 0
		|| rules->sleep_time < 0 || rules->nb_of_phi > 250)
		nb_rules = 1;
	if (argv[5])
	{
		rules->nb_eat = ft_atoi(argv[5]);
		if (rules->nb_eat <= 0)
			nb_rules = 1;
	}
	else
		rules->nb_eat = -1;
	if (init_mutex(rules))
		return (2);
	init_philo(rules);
	return (nb_rules);
}

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	main(int argc, char **argv)
{
	t_rules	rules;
	int		nb_rules;

	if (argc < 5 || argc > 6)
		return (write_error(USAGE));
	nb_rules = init_all(&rules, argv);
	if (nb_rules == 1)
		return (write_error(RULES));
	ready_to_crumble(&rules);
	return (0);
}
