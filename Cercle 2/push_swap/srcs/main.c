/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:47:31 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/29 19:50:14 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_list(t_val *val, t_lon **list_a, t_lon **list_b);

int	main(int argc, char **argv)
{
	t_lon	**list_a;
	t_lon	**list_b;
	t_val	*val;

	if (argc < 2)
		return (0);
	check_args(argc, argv);
	list_a = (t_lon **)malloc(sizeof(t_lon *));
	list_b = (t_lon **)malloc(sizeof(t_lon *));
	val = (t_val *)malloc(sizeof(t_val));
	*list_a = NULL;
	*list_b = NULL;
	init_lon(list_a, argc, argv);
	val_init(val, list_a, list_b);
	if (list_is_sorted(list_a))
	{
		ft_free_lon(list_a);
		ft_free_lon(list_b);
		return (0);
	}
	sort_list(val, list_a, list_b);
	free(val);
	ft_free_lon(list_a);
	ft_free_lon(list_b);
	return (0);
}

void	sort_list(t_val *val, t_lon **list_a, t_lon **list_b)
{
	if (val->size_a <= 5)
		simple_sort(val, list_a, list_b);
	else
	{
		russian_doll_sort(val, list_a, list_b);
		return_from_russia(val, list_a, list_b);
	}
}

void	print_list(t_val *val, t_lon **list_a, t_lon **list_b)
{
	t_lon	*dup;

	dup = *list_a;
	val_init(val, list_a, list_b);
	if (val->size_b > 0)
		ft_printf("Erreur - La size de B est > a 0 : %d\n", val->size_b);
	else
	{
		ft_printf("LISTE A TRIEE :\n");
		while (dup)
		{
			ft_printf("INDEX : %d, NOMBRE : %d\n", dup->index, dup->number);
			dup = dup->next;
		}
	}
}
