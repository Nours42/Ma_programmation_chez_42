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
	int		nbr_grids;
	int		**grids;

	nbr_grids = 1;
	grids = malloc(nbr_grids * sizeof(int *));
	grids[0] = { 4, 4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2 };
	return (grids);
}
