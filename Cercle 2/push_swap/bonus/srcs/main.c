/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:47:31 by sdestann          #+#    #+#             */
/*   Updated: 2023/05/02 13:04:06 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_push_swap.h"

int	main(int argc, char **argv)
{
	t_lon	**list_a;
	t_lon	**list_b;
	char	*line;
	char	*instructions;

	if (argc < 2)
		return (0);
	check_args(argc, argv);
	list_a = (t_lon **)malloc(sizeof(t_lon *));
	list_b = (t_lon **)malloc(sizeof(t_lon *));
	*list_a = NULL;
	*list_b = NULL;
	ft_create_list_to_check_it(list_a, argc, argv);
	instructions = ft_calloc(420000, 1);
	line = ft_calloc(420000, 1);
	if (!line || !instructions)
		return (ft_free(list_a, list_b, line, instructions), 0);
	argc = 0;
	ft_read(line, instructions);
	ft_print_result(instructions, list_a, list_b);
	ft_free(list_a, list_b, line, instructions);
	return (0);
}

void	ft_print_result(char *ins, t_lon **list_a, t_lon **list_b)
{
	ft_do_instructions(list_a, list_b, ins);
	if (*list_a != NULL && list_is_sorted(list_a) == 1
		&& ft_list_size(*list_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return ;
}

void	ft_read(char *line, char *instructions)
{
	int	i;
	int	j;

	j = 0;
	while (read(0, line, 420000))
	{
		i = 0;
		while (line[i])
			instructions[j++] = line[i++];
	}
}
