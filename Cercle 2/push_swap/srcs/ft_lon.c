/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:08:20 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/01 15:13:35 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_lon(t_lon **lon, int argc, char **argv)
{
	t_lon	*new;
	int		i;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		i = 1;
	while (argv[i])
	{
		new = add_number(ft_atoi(argv[i]));
		add_numb_at_end(lon, new);
		i++;
	}
	index_list(lon);
	if (argc == 2)
		ft_free(argv);
}

void	error_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
}

int	get_distance_of_number(t_lon **lon, int index)
{
	t_lon	*dup;
	int		dist_of_number;

	dist_of_number = 0;
	dup = *lon;
	while (dup)
	{
		if (dup->index == index)
			break ;
		dist_of_number++;
		dup = dup->next;
	}
	return (dist_of_number);
}

int	list_is_sorted(t_lon **lon)
{
	t_lon	*dup;

	dup = *lon;
	while (dup->next)
	{
		if (dup->number > dup->next->number)
			return (0);
		dup = dup->next;
	}
	return (1);
}
