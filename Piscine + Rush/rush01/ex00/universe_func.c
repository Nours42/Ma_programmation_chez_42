/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   universe_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amori <amori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:15:12 by amori             #+#    #+#             */
/*   Updated: 2022/11/13 17:41:04 by amori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define UINT unsigned int

UINT	solve(int **universe, int universe_width, int actual, int *rules);
UINT	good_universe(int **universe, int universe_width, int *rules);
void	reveal_universe(int **universe, int universe_width);
int		*get_view(int **universe, int width);
int		get_view_col_bot(int **universe, int width, int col, int all);
int		get_view_col_top(int **universe, int width, int col, int all);
int		get_view_row_right(int **universe, int width, int row, int all);
int		get_view_row_left(int **universe, int width, int row, int all);

int	ft_sqrt(int nb)
{
	unsigned int	i;

	i = 0;
	while (i * i < (unsigned int)nb)
		i ++;
	if (i * i == (unsigned int)nb)
		return ((int)i);
	else
		return (0);
}

UINT	good_universe(int **universe, int width, int *rules)
{
	int	i;
	int	*view;

	view = get_view(universe, width);
	if (view[0] == -1)
	{
		free(view);
		return (0);
	}
	i = 0;
	while (i < width * 4)
	{
		if (view[i] != rules[i + 1] && rules[i + 1] != 0)
		{
			free(view);
			return (0);
		}
		i ++;
	}
	free(view);
	return (1);
}

UINT	valid_atom(int **universe, int y, int x, int atom)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (universe[y][i] == atom)
			return (0);
		i ++;
	}
	i = 0;
	while (i < y)
	{
		if (universe[i][x] == atom)
			return (0);
		i ++;
	}
	return (1);
}

int	*get_view(int **universe, int width)
{
	int	i;
	int	*view;
	int	all;

	all = 0;
	i = 1;
	while (i <= width)
		all += (i ++);
	view = malloc(width * 4 * 4);
	i = 0;
	while (i < width)
	{
		view[i + width * 2] = get_view_col_top(universe, width, i, all);
		view[i + width * 3] = get_view_col_bot(universe, width, i, all);
		view[i] = get_view_row_left(universe, width, i, all);
		view[i + width] = get_view_row_right(universe, width, i, all);
		if (view[i + width * 2] == -1 || view[i + width * 3] == -1)
			view[0] = -1;
		else if (view[i] == -1 || view[i + width] == -1)
			view[0] = -1;
		if (view[0] == -1)
			return (view);
		i ++;
	}
	return (view);
}
