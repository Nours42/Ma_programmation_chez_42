/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amori <amori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:08:18 by amori             #+#    #+#             */
/*   Updated: 2022/11/13 17:25:23 by amori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define UINT unsigned int

UINT	valid_atom(int **universe, int y, int x, int atom);
UINT	good_universe(int **universe, int width, int *rules);
int		ft_sqrt(int nb);
void	error(void);

UINT	solve(int **universe, int W, int D, int *rules)
{
	int	i;

	i = 0;
	while (i < W)
	{
		if (!valid_atom(universe, (W - 1 - D % W), (W - 1 - D / W), i + 1))
		{
			i++;
			continue ;
		}
		else
		{
			universe[W - 1 - D % W][W - 1 - D / W] = i + 1;
			if (good_universe(universe, W, rules) == 1)
				return (1);
			if (D > 0)
				if (solve(universe, W, D - 1, rules))
					return (1);
		}
		i ++;
	}
	return (0);
}

void	reveal_universe(int **universe, int universe_width)
{
	int	x;
	int	y;
	int	out;

	x = 0;
	while (x < universe_width)
	{
		y = 0;
		while (y < universe_width)
		{
			out = universe[y ++][x] + 48;
			write(1, &out, 1);
			if (y != universe_width)
				write(1, " ", 1);
		}
		x ++;
		write(1, "\n", 1);
	}
}

int	*recover_lost_int(char *lost_int, int universe_length)
{
	int	*lost_int_array;
	int	i;
	int	index;

	index = 1;
	i = -1;
	lost_int_array = malloc(universe_length * sizeof(int) + 4);
	lost_int_array[0] = 4;
	while (lost_int[++ i])
		if (lost_int[i] >= '0' && lost_int[i] <= '9')
			lost_int_array[index ++] = lost_int[i] - 48;
	return (lost_int_array);
}

void	ft_free(int	**universe, int *universe_rules)
{
	int	i;

	i = 0;
	free(universe_rules);
	while (i < 4)
	{
		free(universe[i]);
		i ++;
	}
	free(universe);
}

int	main(int argc, char **argv)
{
	int	**universe;
	int	*universe_rules;
	int	i;
	int	n;

	if (argc != 2)
	{
		write(1, "Error\n", 7);
		return (0);
	}
	i = 0;
	n = 4;
	universe_rules = recover_lost_int(argv[1], n * n);
	universe = malloc(n * sizeof(int *));
	while (i < n)
		universe[i ++] = malloc(n * sizeof(int));
	if (solve(universe, n, n * n - 1, universe_rules))
		reveal_universe(universe, n);
	else
		write(1, "Error\n", 6);
	ft_free(universe, universe_rules);
	return (0);
}
