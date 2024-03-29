/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:31:27 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/03 10:48:39 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define USAGE "Usage : number_of_philosophers time_to_die time_to_eat \
		time_to_sleep (number_of_times_each_philosopher_must_eat - option)"
# define RULES "one of your rules is wrong\n"

// to INT_MAX

# include <limits.h>

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

// to semaphore

# include <semaphore.h>

// to use O_CREAT

# include <fcntl.h>

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				nb_eat;
	int				left_fork;
	int				right_fork;
	int				fork1;
	int				fork2;
	pthread_t		thread_id;
	struct s_data	*data;
	long long		last_meal;
}	t_philo;

typedef struct s_data
{
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_eat_min;
	int					all_ate;
	int					death;
	char				fork_available[250];
	sem_t				*forks;
	sem_t				*meal_check;
	sem_t				*check_death;
	sem_t				*print;
	t_philo				philo[250];
	long long			start_time;
}	t_data;

// check.c

int				ft_check_args(char **argv);
int				ft_check_oveflow(char *av);
int				ft_check_digit(char *av);

// exit.c

// void			ft_exit_mutex(t_data *data);
void			ft_check_die(t_data *data, t_philo *philo);
void			exit_launcher(t_data *data);
void			ft_loop_check(t_data *data, t_philo *philo);

// init.c

// int				ft_init_mutex(t_data *data);
int				ft_init_philo(t_data *data);
void			ft_init_data(t_data *data, char **argv, int argc);
int				init_semaphore(t_data *data);

// routine.c

void			*routine(void *philo);
int				ft_create_threads(t_data *data);
void			ft_eat(t_philo *philo, t_data *data);

// main.c

int				main(int argc, char **argv);

// utils.c

void			ft_sleep(int time);
void			ft_print_action(t_data *data, int id, char *str, char *color);
int				ft_atoi(const char *str);
int				ft_is_dead(t_data *data);
long long		ft_timestamp(void);

#endif