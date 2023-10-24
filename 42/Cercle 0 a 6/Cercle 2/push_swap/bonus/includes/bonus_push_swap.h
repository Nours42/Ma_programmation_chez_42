/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_push_swap.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:55:46 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/02 13:03:33 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// lon = list of numbers

#ifndef BONUS_PUSH_SWAP_H
# define BONUS_PUSH_SWAP_H

# include "../../libft/includes/ft_printf.h"
# include "../../libft/includes/libft.h"

typedef struct s_lon
{
	int				number;
	struct s_lon	*next;
}				t_lon;

typedef struct s_ins
{
	char			*line;
	char			*instructions;
}				t_ins;

//ft_check.c

//static int	is_repeat(int num, char **argv, int i);
//static int	isnum(char	*num);
//static inline void	error_gest(int i, char **argv);
void	check_args(int argc, char **argv);
int		ft_check_arg(char *s);

// ft_do_instructions.c

void	ft_do_instructions(t_lon **list_a, t_lon **list_b, char *result);
void	ft_act_on_stack(char *instruction, t_lon **list_a, t_lon **list_b);
void	ft_r_actions(char *instruction, t_lon **stack_a, t_lon **stack_b);

//ft_free_lon.c

void	ft_free(t_lon **list_a, t_lon **list_b, char *line, char *instructions);
void	ft_free_lon(t_lon **lon);
void	ft_free_tab_of_tab_char(char **str);

//ft_list.c

t_lon	*add_number(int numb);
void	add_numb_at_begin(t_lon **lon, t_lon *new_number);
void	add_numb_at_end(t_lon **lon, t_lon *new_number);
t_lon	*get_last(t_lon *head);
size_t	ft_list_size(t_lon *lon);

//ft_lon.c

void	ft_create_list_to_check_it(t_lon **list_a, int argc, char **argv);
void	error_msg(char *msg);
int		list_is_sorted(t_lon **lon);

//main.c

//static void	sort_list(t_lon **list_a, t_lon **list_b);
int		main(int argc, char **argv);
void	ft_print_result(char *ins, t_lon **stack_a, t_lon **stack_b);
size_t	ft_count_n_checker(char *r);
void	ft_read(char *line, char *instructions);

//move_p_s.c

void	sa(t_lon **list_a);
void	sb(t_lon **list_b);
void	ss(t_lon **list_a, t_lon **list_b);
void	pa(t_lon **list_a, t_lon **list_b);
void	pb(t_lon **list_a, t_lon **list_b);

//move_r.c

void	ra(t_lon **list_a);
void	rb(t_lon **list_b);
void	rr(t_lon **list_a, t_lon **list_b);

//move_rr.c

void	rra(t_lon **list_a);
void	rrb(t_lon **list_b);
void	rrr(t_lon **list_a, t_lon **list_b);

//move.c

void	push(t_lon **list_from, t_lon **list_dest);
void	swap(t_lon **list);
void	rotate(t_lon **list);
void	reverse_rotate(t_lon **list);

#endif