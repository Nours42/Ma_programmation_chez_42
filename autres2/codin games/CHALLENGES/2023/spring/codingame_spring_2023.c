/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codingame_spring_2023.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:46:31 by sdestann          #+#    #+#             */
/*   Updated: 2023/06/01 17:14:47 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct	s_hexa
{
	int			type;				// 0 for empty, 1 for eggs, 2 for crystal
	int			initial_resources;	// the initial amount of eggs/crystals on this cell
	int			neigh_0;			// the index of the neighbouring cell for each direction
	int			neigh_1;
	int			neigh_2;
	int			neigh_3;
	int			neigh_4;
	int			neigh_5;
	int			resources;			// the current amount of eggs/crystals on this cell
	int			my_ants;			// the amount of your ants on this cell
	int			opp_ants;			// the amount of opponent ants on this cell
	struct s_hexa	*next;
}				t_hexa;

typedef struct	s_map
{
	int				number_of_cells;	// amount of hexagonal cells in this map
	int				number_of_bases;	// amount of bases cells in this map
	int				my_base_index;		// index of my base
	int				opp_base_index;		// index of opposent base
	struct s_hexa	**hexa;
}				t_map;

t_hexa	*add_cells_first_values(t_hexa hexa_temp)
{
    t_hexa  *new_hexa;

	new_hexa = (t_hexa*)malloc((sizeof(t_hexa)));
	if (!new_hexa)
		return (NULL);
	new_hexa->type = hexa_temp.type;
	new_hexa->initial_resources = hexa_temp.initial_resources;
	new_hexa->neigh_0 = hexa_temp.neigh_0;
	new_hexa->neigh_1 = hexa_temp.neigh_1;
	new_hexa->neigh_2 = hexa_temp.neigh_2;
	new_hexa->neigh_3 = hexa_temp.neigh_3;
	new_hexa->neigh_4 = hexa_temp.neigh_4;
	new_hexa->neigh_5 = hexa_temp.neigh_5;
	new_hexa->resources = 0;
	new_hexa->my_ants = 0;
	new_hexa->opp_ants = 0;
	new_hexa->next = NULL;
	return (new_hexa);
}

t_hexa	*get_last(t_hexa *hexa)
{
	if (!hexa)
		return (NULL);
	while (hexa->next)
		hexa = hexa->next;
	return (hexa);
}

void	add_cell_at_end(t_hexa **hexa, t_hexa *new_hexa)
{
	t_hexa	*temp;

	if (*hexa)
	{
		temp = get_last(*hexa);
		temp->next = new_hexa;
	}
	else
		*hexa = new_hexa;
}

int	search_eggs_or_crystals(t_map *map, int type)
{
	t_hexa	*dup;
	int		i;
	int		max_of;
	int		coord_of;

	i = 0;
	max_of = 0;
	coord_of = 0;
	dup = *(map->hexa);
	while (i < map->number_of_cells)
	{
		if (dup->type == type)
		{
			if (dup->resources > max_of)
			{
				max_of = dup->resources;
				coord_of = i;
			}
			else
				dup = dup->next;
		}
		i++;
	}
	return (coord_of);
}

int main(void)
{
	t_map	*map;
	t_hexa	hexa_temp;
	int		nbc;
	int		i;
	int		coord_max_egg;
	int		coord_max_crystal;
	
	nbc  = 0;
	i = 0;
	coord_max_egg = 0;
	coord_max_crystal = 0;
	map = (t_map*)malloc(sizeof(t_map) + 1);
	map->hexa = (t_hexa**)malloc((sizeof(t_hexa*)));
	if (!map->hexa)
		return (0);
	scanf("%d", &nbc);
	while (i < nbc)
	{
		map->hexa[i] = (t_hexa*)malloc((sizeof(t_hexa)));
		if (!map->hexa)
			return (0);
		scanf("%d%d%d%d%d%d%d%d", &hexa_temp.type, &hexa_temp.initial_resources, 
			&hexa_temp.neigh_0, &hexa_temp.neigh_1, &hexa_temp.neigh_2,
			&hexa_temp.neigh_3, &hexa_temp.neigh_4, &hexa_temp.neigh_5);
		map->hexa[i] = add_cells_first_values(hexa_temp);
		add_cell_at_end(map->hexa, map->hexa[i]);
		i++;	
	}
    scanf("%d", &map->number_of_bases);
	i = 0;
    while (i < map->number_of_bases)
	{
        scanf("%d", &map->my_base_index);
		i++;
    }
	i = 0;
    while (i < map->number_of_bases)
	{
        scanf("%d", &map->opp_base_index);
		i++;
    }
    // game loop
    while (1) {
		i = 0;
        while (i < map->number_of_cells)
		{
            scanf("%d%d%d", &map->hexa[i]->resources,&map->hexa[i]->my_ants, &map->hexa[i]->opp_ants);
			printf("LINE %i %i %i", i, i, i);
			i++;
        }
        coord_max_egg = search_eggs_or_crystals(&map, 1);
		coord_max_crystal = search_eggs_or_crystals(&map, 2);
		if (map->hexa[coord_max_egg]->resources / 2 >= map->hexa[coord_max_egg]->resources)
			printf("LINE %i %i %i\n", map->my_base_index, coord_max_crystal, 1);
		else
			printf("LINE %i %i %i\n", map->my_base_index, coord_max_egg, 2);
    }

    return 0;
}
