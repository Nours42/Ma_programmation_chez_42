/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:31:27 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/26 13:49:50 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define USAGE "Usage : number_of_philosophers time_to_die time_to_eat \
		time_to_sleep (number_of_times_each_philosopher_must_eat - option)"
# define RULES "one of your rules is wrong\n"

// to write, usleep

# include <unistd.h>

// to free

# include <stdlib.h>

// to memset

# include <string.h>

// to printf

# include <stdio.h>

// to gettimeofday

# include <sys/time.h>

// to pthread_create

# include <pthread.h>

struct	s_rules;

typedef struct s_philo
{
	int					id;
	int					nb_ate;
	int					left_fork_id;
	int					right_fork_id;
	long long			time_of_last_meal;
	struct s_rules		*rules;
	pthread_t			thread_id;
}				t_philo;

typedef struct s_rules
{
	int					nb_of_phi;
	int					die_time;
	int					eat_time;
	int					sleep_time;
	int					nb_eat;
	int					already_died;
	int					all_ate;
	long long			first_timestamp;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		forks[250];
	pthread_mutex_t		writing;
	t_philo				philo[250];
}				t_rules;

// luncher.c

void		philo_eats(t_philo *philo);
void		*p_thread(void *void_philo);
void		exit_launcher(t_rules *rules, t_philo *philos);
void		death_checker(t_rules *r, t_philo *p);
int			ready_to_crumble(t_rules *rules);

// main.c

int			init_mutex(t_rules *rules);
int			init_philo(t_rules *rules);
int			init_all(t_rules *rules, char **argv);
long long	timestamp(void);
int			main(int argc, char **argv);

// utils.c

int			ft_atoi(const char *str);
long long	time_diff(long long past, long long pres);
void		smart_sleep(long long time, t_rules *rules);
void		action_print(t_rules *rules, int id, char *string);
int			write_error(char *str);

#endif