/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:18:13 by kaly              #+#    #+#             */
/*   Updated: 2023/09/28 12:07:43 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_data(t_data *data)
{
	data->x = WINDOW_W;
	data->y = WINDOW_H;
	data->exit = 1;
	data->ya = 0.00;
	data->xa = 0.00;
	data->anglerad = 0.00;
	data->first_x = 0.00;
	data->dist_x = 0.00;
	data->first_y = 0.00;
	data->dist_y = 0.00;
	data->dist = 0.00;
	data->orient = 0.00;
	data->beta = 30.00;
	data->horizon = WINDOW_H / 2;
	data->i = 0;
	data->o = 0;
	data->scale = 60.0000000 / WINDOW_W;
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	ft_check_arg(argc, argv);
	data = malloc(sizeof(t_data));
	if (!data)
		return (MLX_ERROR);
	i = ft_check(argc, argv, data);
	if (i == 1)
		ft_clean_when_verif_map_ko(data);
	else if (i == 2)
		ft_clean_before_creating_map(data);
	init_data(data);
	ft_create_window(data);
	return (0);
}
