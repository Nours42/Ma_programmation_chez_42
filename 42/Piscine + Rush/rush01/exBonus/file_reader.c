/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amori <amori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:03:13 by amori             #+#    #+#             */
/*   Updated: 2022/11/13 16:09:09 by amori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	**read_grids(void)
{
	int		c;
	FILE	*file;
	int		nbr_grids;
	int		**grids;
	int		i;
	int		j;
	int		len;

	i = -1;
	nbr_grids = 3;
	grids = malloc(nbr_grids * sizeof(int *));
	file = fopen("grids.pierre", "r");
	if (file)
	{
		c = getc(file);
		while (c != EOF)
		{
			len = 0;
			i ++;
			while (c != '\n')
			{
				if (c <= '9' && c >= '0')
				{
					if (len != 0)
						grids[i][(j++)] = c - 48;
					else
					{
						len = c - 48;
						grids[i] = malloc((len * len + 1) * sizeof(int));
						j = 1;
						grids[i][(j - 1)] = len;
					}
				}
				c = getc(file);
			}
			c = getc(file);
		}
		fclose(file);
	}
	return (grids);
}
