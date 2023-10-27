/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:08:20 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/02 12:16:44 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_push_swap.h"

void	ft_create_list_to_check_it(t_lon **list_a, int argc, char **argv)
{
	int		i;
	t_lon	*temp;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		i = 1;
	while (argv[i])
	{
		temp = add_number(ft_atoi(argv[i]));
		add_numb_at_end(list_a, temp);
		i++;
	}
	if (argc == 2)
		ft_free_tab_of_tab_char(argv);
}

void	error_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
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
