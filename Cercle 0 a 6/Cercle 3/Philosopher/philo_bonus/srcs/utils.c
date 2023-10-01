/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:29:18 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/01 13:02:38 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str)
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

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

long long	ft_timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_sleep(long long time, t_data *data)
{
	long long	i;

	i = ft_timestamp();
	while (!(data->death))
	{
		if (time_diff(i, ft_timestamp()) >= time)
			break ;
		usleep(50);
	}
}

void	ft_print_action(t_data *data, int id, char *string, char *color)
{
	sem_wait(data->writing);
	if (!(data->death))
	{
		printf("%s", color);
		printf("%lli ", ft_timestamp() - data->start_time);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	sem_post(data->writing);
	return ;
}
