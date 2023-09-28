/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_prog_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:37:41 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/26 12:11:12 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_clean_when_verif_map_ko(t_data *data)
{
	ft_quit2(data);
	free(data);
	exit (EXIT_FAILURE);
}

int	ft_quit(t_data *data)
{
	ft_printf("\n\n\033[31m");
	ft_printf("  %%%%%%%%    %%%%%%%%   %%%%   %%%%  %%%%%%%%%%%%\n");
	ft_printf(" %%%%      %%%%  %%%%  %%%%%% %%%%%%  %%%%\n");
	ft_printf(" %%%% %%%%%%  %%%%%%%%%%%%  %%%% %% %%%%  %%%%%%%%\n");
	ft_printf(" %%%%  %%%%  %%%%  %%%%  %%%%   %%%%  %%%%\n");
	ft_printf("  %%%%%%%%   %%%%  %%%%  %%%%   %%%%  %%%%%%%%%%%%\n");
	ft_printf("                                          \n");
	ft_printf("           %%%%%%%%   %%%%  %%%%  %%%%%%%%%%%%  %%%%%%%%%%\n");
	ft_printf("          %%%%  %%%%  %%%%  %%%%  %%%%      %%%%  %%%%\n");
	ft_printf("          %%%%  %%%%  %%%%  %%%%  %%%%%%%%    %%%%%%%%%%\n");
	ft_printf("          %%%%  %%%%   %%%%%%%%   %%%%      %%%%  %%%%\n");
	ft_printf("           %%%%%%%%     %%%%    %%%%%%%%%%%%  %%%%  %%%%\n");
	ft_printf("\033[0m\n");
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	ft_quit2(data);
	free(data->mlx_ptr);
	free(data);
	exit (0);
}

void	ft_quit2(t_data *data)
{
	int	i;

	i = -1;
	while (data->map[++i])
		free(data->map[i]);
	free(data->map);
	free(data->floor_hex_color);
	free(data->ceiling_hex_color);
}
