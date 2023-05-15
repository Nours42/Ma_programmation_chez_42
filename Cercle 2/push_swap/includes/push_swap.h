/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:55:46 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/29 09:41:26 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// lon = list of numbers

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"

typedef struct s_lon
{
	int				number;
	int				index;
	struct s_lon	*next;
}				t_lon;

typedef struct s_val
{
	int				index_max;
	int				size_a;
	int				size_b;
	int				div;
	int				rest;
}				t_val;

//ft_check.c

//static int	is_repeat(int num, char **argv, int i);
//static int	isnum(char	*num);
void	check_args(int argc, char **argv);
//static inline void	error_gest(int i, char **argv);

//ft_free_lon.c

void	ft_free(char **str);
void	ft_free_lon(t_lon **lon);

//ft_index.c

//static t_lon	*get_next_min(t_lon **list);
void	index_list(t_lon **list);
int		min_index(t_lon **list);

//ft_list.c

t_lon	*add_number(int numb);
void	add_numb_at_begin(t_lon **lon, t_lon *new_number);
void	add_numb_at_end(t_lon **lon, t_lon *new_number);
t_lon	*get_last(t_lon *head);
size_t	ft_list_size(t_lon *lon);

//ft_lon.c

void	init_lon(t_lon **stack, int argc, char **argv);
void	error_msg(char *msg);
int		get_distance_of_number(t_lon **lon, int index);
int		list_is_sorted(t_lon **lon);

//main.c

//static void	sort_list(t_lon **list_a, t_lon **list_b);
int		main(int argc, char **argv);
void	sort_list(t_val *val, t_lon **list_a, t_lon **list_b);

//move_p_s.c

void	pa(t_val *val, t_lon **list_a, t_lon **list_b);
void	pb(t_val *val, t_lon **list_a, t_lon **list_b);
void	sa(t_val *val, t_lon **list_a, t_lon **list_b);
void	sb(t_val *val, t_lon **list_a, t_lon **list_b);
void	ss(t_val *val, t_lon **list_a, t_lon **list_b);

//move_r.c

void	ra(t_val *val, t_lon **list_a, t_lon **list_b);
void	rb(t_val *val, t_lon **list_a, t_lon **list_b);
void	rr(t_val *val, t_lon **list_a, t_lon **list_b);

//move_rr.c

void	rra(t_val *val, t_lon **list_a, t_lon **list_b);
void	rrb(t_val *val, t_lon **list_a, t_lon **list_b);
void	rrr(t_val *val, t_lon **list_a, t_lon **list_b);

//move.c

void	push(t_lon **list_from, t_lon **list_dest);
void	swap(t_lon **list);
void	rotate(t_lon **list);
void	reverse_rotate(t_lon **list);

//russian_doll_sort.c

void	val_init(t_val *val, t_lon **list_a, t_lon **list_b);
void	russian_doll_sort(t_val *val, t_lon **list_a, t_lon **list_b);
void	ft_division(t_val *val, t_lon **list_a, t_lon **list_b);
void	return_from_russia(t_val *val, t_lon **list_a, t_lon **list_b);

//small_sort.c

void	simple_sort(t_val *val, t_lon **list_a, t_lon **list_b);
void	sort_three(t_val *val, t_lon **list_a, t_lon **list_b);
//static inline void	sort_four(t_val *val, t_lon **list_a, t_lon **list_b);
// static void	sort_five(t_val *val, t_lon **list_a, t_lon **list_b);

#endif