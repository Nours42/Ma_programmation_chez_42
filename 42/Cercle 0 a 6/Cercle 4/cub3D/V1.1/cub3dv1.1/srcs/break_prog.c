/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:37:41 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/28 12:04:09 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_clean_before_creating_map(t_data *data)
{
	free(data->map);
	free(data);
	exit (EXIT_FAILURE);
}

void	ft_clean_when_verif_map_ko(t_data *data)
{
	ft_quit2(data, 1);
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
	mlx_destroy_image(data->mlx_ptr, data->wall_n);
	mlx_destroy_image(data->mlx_ptr, data->wall_e);
	mlx_destroy_image(data->mlx_ptr, data->wall_s);
	mlx_destroy_image(data->mlx_ptr, data->wall_w);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_fc_color(data, 2);
	ft_quit2(data, 1);
	free(data->mlx_ptr);
	free(data);
	exit (0);
}

void	ft_quit2(t_data *data, int j)
{
	int	i;

	i = -1;
	while (data->map[++i])
		free(data->map[i]);
	free(data->map);
	if (j == 1)
	{
		free(data->no_texture);
		free(data->so_texture);
		free(data->ea_texture);
		free(data->we_texture);
	}
}

void	free_fc_color(t_data *data, int i)
{
	int	j;

	j = -1;
	if (i == 2)
	{
		free(data->floor_hex_color);
		free(data->ceiling_hex_color);
		i--;
	}
	if (i == 1)
	{
		while (data->split_color_c[++j])
			free(data->split_color_c[j]);
		free(data->split_color_c);
	}
	j = -1;
	while (data->split_color_f[++j])
		free(data->split_color_f[j]);
	free(data->split_color_f);
}