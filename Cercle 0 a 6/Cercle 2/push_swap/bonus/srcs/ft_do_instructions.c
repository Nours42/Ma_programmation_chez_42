/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:06:07 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/02 11:59:44 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_push_swap.h"

void	ft_do_instructions(t_lon **list_a, t_lon **list_b, char *result)
{
	int		i;
	int		j;
	char	*instruction;

	i = 0;
	while (result[i])
	{
		j = 0;
		instruction = ft_calloc(10, 1);
		if (!instruction)
			return ;
		while (result && result[i] != '\n')
			instruction[j++] = result[i++];
		instruction[j] = result[i];
		i++;
		if (ft_check_arg(instruction) == 0)
			error_msg("Error - one of instruction is incorrect");
		j = 0;
		ft_act_on_stack(instruction, list_a, list_b);
		if (instruction)
			free(instruction);
	}
}

void	ft_act_on_stack(char *instruction, t_lon **list_a, t_lon **list_b)
{
	if (instruction[0] == 's')
	{
		if (instruction[1] == 'a')
			sa(list_a);
		else if (instruction[1] == 'b')
			sb(list_b);
		else if (instruction[1] == 's')
			ss(list_a, list_b);
	}
	else if (instruction[0] == 'p')
	{
		if (instruction[1] == 'a')
			pa(list_a, list_b);
		else if (instruction[1] == 'b')
			pb(list_a, list_b);
	}
	else if (instruction[0] == 'r')
		ft_r_actions(instruction, list_a, list_b);
}

void	ft_r_actions(char *instruction, t_lon **stack_a, t_lon **stack_b)
{
	if (instruction[1] == 'a')
		ra(stack_a);
	else if (instruction[1] == 'b')
		rb(stack_b);
	else if (instruction[1] == 'r')
	{
		if (instruction[2] == '\n')
			rr(stack_a, stack_b);
		else if (instruction[2] == 'a')
			rra(stack_a);
		else if (instruction[2] == 'b')
			rrb(stack_b);
		else if (instruction[2] == 'r')
			rrr(stack_a, stack_b);
	}
}
