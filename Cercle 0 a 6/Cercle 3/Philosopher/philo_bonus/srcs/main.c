/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:32:47 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/01 13:02:45 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		ret;

	if (argc != 5 && argc != 6)
		return (write_error("Wrong amount of arguments"));
	else
		data = (t_data *)malloc(sizeof(t_data));
	if (ft_check_args(argv))
		return (error_manager(3));
	else
		ret = init_all(data, argv);
	if ((ret))
		return (error_manager(ret));
	if (launcher(data))
		return (write_error("There was an error creating the threads"));
	return (0);
}

int	write_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, "Error: ", 7);
	write(2, str, len);
	write(2, "\n", 1);
	return (1);
}

int	error_manager(int error)
{
	if (error == 1)
		return (write_error("At least one wrong argument"));
	else if (error == 2)
		return (write_error("Fatal error when intializing semaphores"));
	else if (error == 3)
		return (write_error("At least one argument is overflow"));
	else if (error == 4)
		return (write_error("At least one argument is NaN"));
	return (1);
}

int	ft_is_dead(t_data *data)
{
	sem_wait(data->meal_check);
	if (data->death == 1)
	{
		sem_post(data->meal_check);
		return (1);
	}
	else
	{
		sem_post(data->meal_check);
		return (0);
	}
}
