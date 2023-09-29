/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:31:27 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/29 16:53:04 by sdestann         ###   ########.fr       */
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

struct s_data;

typedef	struct			s_philo
{
	int					id;
	int					nb_eat;
	int					left_fork_id;
	int					right_fork_id;
	long long			last_meal;
	struct s_data		*data;
	pthread_t			death_check;
	pid_t				proc_id;
}						t_philo;

typedef struct			s_data
{
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_eat_min;
	int					dieded;
	int					all_ate;
	long long			first_timestamp;
	sem_t				*meal_check;
	sem_t				*check_death;
	sem_t				*forks;
	sem_t				*writing;
	t_philo				philo[250];
}						t_data;

// 	check.c		//

int			ft_check_digit(char *av);
int			ft_check_oveflow(char *av);
int			ft_check_args(char **av);

// 	exit.c		//

void		*ft_check_die(void *void_philo);
void		ft_loop_check(t_data *data, t_philo *philo);
void		ft_exit_mutex(t_data *data);

// 	init.c		//

int			ft_init_data(t_data *data, char **argv);
int			init_philos(t_data *data);
int			init_semaphore(t_data *data);

// 	main.c		//

int			main(int argc, char **argv);

// 	routine.c	//

void		ft_take_forks(t_philo *philo, t_data *data);
void		ft_eat(t_philo *philo, t_data *data);
void		routine(void *void_phil);
void		exit_launcher(t_data *data);
int			launcher(t_data *data);


// 	utils.c		//

int			ft_atoi(const char *str);
long long	ft_timestamp(void);
void		ft_sleep(int time);
void		ft_print_action(t_data *data, int id, char *str, char *color);
int			ft_is_dead(t_data *data);


#endif