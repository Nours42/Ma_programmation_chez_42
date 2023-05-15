/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   mainAdri.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: amori <amori@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/11/12 09:08:18 by amori			 #+#	#+#			 */
/*   Updated: 2022/11/13 16:55:37 by amori			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define UINT unsigned int

void	interface_adri_to_seb(int  **grid, int *rules, int size);
int		**read_grids(void);
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

	out = universe_width + 48;
	write(1, "Solution :\n", 11);
	x = 0;
	while (x < universe_width)
	{
		y = 0;
		while (y < universe_width)
		{
			out = universe[y ++][x] + 48;
			write(1, &out, 1);
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

	index = 0;
	i = -1;
	lost_int_array = malloc(universe_length * sizeof(int));
	while (lost_int[++ i])
		if (lost_int[i] >= '0' && lost_int[i] <= '9')
			lost_int_array[index ++] = lost_int[i] - 48;
	return (lost_int_array);
}

void	ft_free(int **universe, int *universe_rules, int n)
{
	int	i;

	i = 0;
	free(universe_rules);
	while (i < n)
	{
		free(universe[i]);
		i ++;
	}
	free(universe);
}

int	main(void)
{
	int	**universe;
	int	*universe_rules;
	int	i;
	int	n;
	int	**grids;
	int	nbr_grids;
	int	out;

	grids = read_grids();

	nbr_grids = 0;
	while (nbr_grids < 3)
	{
		i = 0;
		n = grids[nbr_grids][0];

		universe_rules = grids[nbr_grids];
		universe = malloc(n * sizeof(int *));
		write (1, "\033[0m", 4);
		write(1, "Universe ", 9);
		out = nbr_grids + 49;
		write(1, &out, 1);
		write(1, "\n", 1);
		while (i < n)
			universe[i ++] = malloc(n * sizeof(int));
		if (solve(universe, n, n * n - 1, universe_rules))
		{
			interface_adri_to_seb(universe, universe_rules, n);	
		}
		else
			write(1, "Error\n", 6);
		nbr_grids ++;
		write(1, "\n", 1);
		ft_free(universe, universe_rules, n);
	}
	return (0);
}
