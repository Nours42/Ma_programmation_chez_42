/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:29:18 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/29 16:01:07 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int			ft_atoi(const char *str)
{
	long int	n;
	int			sign;

	n = 0;
	sign = 1;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == '-')
		return (-1);
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			n = n * 10 + (*str++ - '0');
		else
			return (-1);
	}
	return ((int)(n * sign));
}

long long	ft_timestamp(void)
{
	struct timeval	*time;

	gettimeofday(time, NULL);
	return ((time->tv_sec * 1000) + (time->tv_usec / 1000));
}

void	ft_sleep(int time)
{
	long long	start;

	start = ft_timestamp();
	while (1)
	{
		if (ft_timestamp() - start >= time)
			break ;
		usleep(50);
	}
}

void	ft_print_action(t_data *data, int id, char *str, char *color)
{
	long long	time;

	time = ft_timestamp() - data->start_time;
	sem_wait(data->writing);
	if (!(data->dieded))
		printf("%s %lli %i %s\n", color, time, id, str);
	sem_post(data->writing);
}

int	ft_is_dead(t_data *data)
{
	sem_wait(data->check_death)
	if (data->death == 1)
	{
		sem_post(data->check_death);
		return (1);
	}
	else
	{
		sem_post(data->check_death);
		return (0);
	}
}