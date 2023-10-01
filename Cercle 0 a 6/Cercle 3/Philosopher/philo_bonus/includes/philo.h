/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:31:27 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/01 13:10:07 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <limits.h>

struct	s_data;

typedef struct s_philo
{
	int					id;
	int					nb_eat;
	int					fork1;
	int					fork2;
	int					left_fork_id;
	int					right_fork_id;
	long long			last_meal;
	struct s_data		*data;
	pthread_t			proc_id;
}						t_philo;

typedef struct s_data
{
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_eat_min;
	int					death;
	int					all_ate;
	int					forks_available;
	long long			start_time;
	sem_t				*meal_check;
	sem_t				*forks;
	sem_t				*writing;
	t_philo				philo[250];
}						t_data;

// 	check.c		//

int			ft_check_digit(char *argv);
int			ft_check_overflow(char *argv);
int			ft_check_args(char **argv);

// 	init.c		//

int			init_semaphore(t_data *data);
int			init_all(t_data *data, char **argv);
int			init_philo(t_data *data);

// 	main.c		//

int			main(int argc, char **argv);
int			write_error(char *str);
int			error_manager(int error);
int			ft_is_dead(t_data *data);

// 	launcher.c	//

void		philo_eats(t_philo *philo);
void		*p_process(void *void_phil);
void		exit_launcher(t_data *data, t_philo *philo);
void		*death_checker(t_data *data, t_philo *philo, int i);
int			launcher(t_data *data);

// 	utils.c		//

int			ft_atoi(const char *str);
long long	time_diff(long long past, long long pres);
long long	ft_timestamp(void);
void		ft_sleep(long long time, t_data *data);
void		ft_print_action(t_data *data, int id, char *str, char *color);

#endif