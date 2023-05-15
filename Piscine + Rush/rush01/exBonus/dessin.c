/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dessin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:52:21 by sdestann          #+#    #+#             */
/*   Updated: 2022/11/13 16:55:51 by amori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	print_line(int size)
{
	write (1, "\033[0;34m", 7);
	write (1, "   |", 4);
	while (size >= 1)
	{
		write (1, "   |", 4);
		size--;
	}
	write (1, "   \n", 4);
}

void	print_line_plus(int size)
{
	write (1, "\033[0;34m", 7);
	write (1, "---+", 4);
	while (size >= 1)
	{
		write (1, "---+", 4);
		size--;
	}
	write (1, "---\n", 4);
}

void	print_line_char(int size, int *tab, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	write (1, " ", 1);
	j = 0;
	while (j <= (size - 1))
	{
		k = tab[i + j] + 48;
		if (tab[i + j] == -1)
			k = 32;
		else if (tab[i + j] == 0)
			k = '.';
		write (1, "\033[0m", 4);
		write (1, &k, 1);
		if (j == size - 1)
			write (1, " ", 1);
		else
		{
			write (1, "\033[0;34m", 7);
			write (1, " | ", 3);
		}
		j++;
	}
}

void	dessin_de_la_grille(int *tab, int size)
{
	int	i;
	int	size_adapt;

	i = 0;
	size_adapt = size;
	size += 2;
	print_line(size_adapt);
	while (i < ((size * size) - 1))
	{
		print_line_char(size, tab, i);
		write (1, " \n", 2);
		if (i < ((size * size) - size))
		{
			print_line(size_adapt);
			print_line_plus(size_adapt);
			print_line(size_adapt);
		}
		i += size;
	}
	print_line(size_adapt);
}

void	interface_adri_to_seb(int	**grid, int *rules, int size)
{
	int	*output;
	int	i;
	int	x;
	int	y;

	output = malloc(((size + 2) * (size + 2)) * sizeof(int));
	output[0] = -1;
	i = 0;
	y = 0;
	while (++i < size + 1)
		output[i] = rules[i];
	output[i ++] = -1;
	while (y < size)
	{
		output[i ++] = rules[12 + y + 1];
		x = 0;
		while (x < size)
			output[i ++] = grid[(x ++)][y];
		output[i ++] = rules[8 + (y ++) + 1];
	}
	output[i ++] = -1;
	while (x - size < size)
		output[(i ++)] = rules[4 + (x ++) - size + 1];
	output[i ++] = -1;
	dessin_de_la_grille(output, size);
}
