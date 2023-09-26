/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:40:05 by kaly              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/09/26 11:57:45 by sdestann         ###   ########.fr       */
=======
/*   Updated: 2023/09/26 10:01:21 by sdestann         ###   ########.fr       */
>>>>>>> e5518b7c21a263b6eca4816ebf231b237429214e
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

<<<<<<< HEAD
void	ft_init_part_one(t_data *data, int i, int j)
=======
void	ft_init_part_one(t_data *data, int i)
>>>>>>> e5518b7c21a263b6eca4816ebf231b237429214e
{
	data->first_x = data->delta_x * (data->player_x % PXL) / PXL;
	data->first_xa = sqrt((data->first_x * data->first_x) - ((data->player_x
					% PXL) * (data->player_x % PXL)));
	data->first_y = data->delta_y * ((100 * i)
<<<<<<< HEAD
			+ (data->player_y % PXL * j)) / PXL;
	data->first_ya = sqrt((data->first_y * data->first_y) - (((100 * i)
					+ (data->player_y % PXL * j)) * ((100 * i)
					+ (data->player_y % PXL * j))));
=======
			+ (data->player_y % PXL * -i)) / PXL;
	data->first_ya = sqrt((data->first_y * data->first_y) - (((100 * i)
					+ (data->player_y % PXL * -i)) * ((100 * i)
					+ (data->player_y % PXL * -i))));
>>>>>>> e5518b7c21a263b6eca4816ebf231b237429214e
	data->dist_x = data->first_x;
	data->dist_y = data->first_y;
}

<<<<<<< HEAD
void	ft_init_part_two(t_data *data, int i, int j)
=======
void	ft_init_part_two(t_data *data, int i)
>>>>>>> e5518b7c21a263b6eca4816ebf231b237429214e
{
	data->first_x = data->delta_x * (100 - (data->player_x % PXL)) / PXL;
	data->first_xa = sqrt((data->first_x * data->first_x)
			- ((100 - data->player_x % PXL)
				* (100 - data->player_x % PXL)));
	data->first_y = data->delta_y * ((100 * i)
<<<<<<< HEAD
			+ (data->player_y % PXL * j)) / PXL;
	data->first_ya = sqrt((data->first_y * data->first_y)
			- (((100 * i) + (data->player_y % PXL * j))
				* ((100 * i) + (data->player_y % PXL * j))));
=======
			+ (data->player_y % PXL * -i)) / PXL;
	data->first_ya = sqrt((data->first_y * data->first_y)
			- (((100 * i) + (data->player_y % PXL * -i))
				* ((100 * i) + (data->player_y % PXL * -i))));
>>>>>>> e5518b7c21a263b6eca4816ebf231b237429214e
	data->dist_x = data->first_x;
	data->dist_y = data->first_y;
}

void	ft_turn_orient(t_data *data)
{
	if (data->orient > 0 && data->orient < 90)
	{
<<<<<<< HEAD
		ft_init_part_one(data, 1, -1);
=======
		ft_init_part_one(data, 1);
>>>>>>> e5518b7c21a263b6eca4816ebf231b237429214e
		ft_check_wall_ne(data);
	}
	else if (data->orient > -90 && data->orient < 0)
	{
<<<<<<< HEAD
		ft_init_part_two(data, 1, -1);
=======
		ft_init_part_two(data, 1);
>>>>>>> e5518b7c21a263b6eca4816ebf231b237429214e
		ft_check_wall_se(data);
	}
	else if (data->orient < -90)
	{
<<<<<<< HEAD
		ft_init_part_two(data, 0, 1);
=======
		ft_init_part_two(data, 0);
>>>>>>> e5518b7c21a263b6eca4816ebf231b237429214e
		ft_check_wall_sw(data);
	}
	else
	{
<<<<<<< HEAD
		ft_init_part_one(data, 0, 1);
=======
		ft_init_part_one(data, 0);
>>>>>>> e5518b7c21a263b6eca4816ebf231b237429214e
		ft_check_wall_nw(data);
	}
}

void	ft_init_first(t_data *data)
{
	data->i = 0;
	data->o = 0;
	ft_turn_orient(data);
	data->rad_beta = cos(data->beta * (M_PI / 180.00));
	if (data->dist_x < data->dist_y)
		data->dist = data->dist_x * data->rad_beta;
	else
		data->dist = data->dist_y * data->rad_beta;
}

void	ft_init_delta(t_data *data)
{
	data->anglerad = data->orient * (M_PI / 180.00);
	if ((data->orient < 90 && data->orient > 0) || data->orient < -90)
	{
		data->xa = 100 / tan(data->anglerad);
		data->ya = 100 * tan(data->anglerad);
	}
	else
	{
		data->xa = 100 / tan(data->anglerad) * (-1);
		data->ya = 100 * tan(data->anglerad) * (-1);
	}
	data->delta_x = sqrt((data->xa * data->xa) + 100 * 100);
	data->delta_y = sqrt((data->ya * data->ya) + 100 * 100);
	ft_init_first(data);
}
