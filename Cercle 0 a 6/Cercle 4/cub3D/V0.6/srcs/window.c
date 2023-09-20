/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:40:05 by kaly              #+#    #+#             */
/*   Updated: 2023/09/20 09:19:01 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

typedef struct s_values
{
	int		index;
	int		indexY;
	int		maxX;
	int		maxY;
	int		i;
	int		x;
	int		stepX;
    int 	stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	cameraX;
	//calculate ray position and direction
	double	rayDirX;
	double	rayDirY;
	
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
}				t_values;

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
		ft_quit(data);
	// if (keysym == 119 || keysym == 65362)
	// 	if (data->map[data->pl_y - 1][data->pl_x] != '1')
	// 		ft_move_up(data);
	// if (keysym == 115 || keysym == 65364)
	// 	if (data->map[data->pl_y + 1][data->pl_x] != '1')
	// 		ft_move_down(data);
	// if (keysym == 97 || keysym == 65361)
	// 	if (data->map[data->pl_y][data->pl_x - 1] != '1')
	// 		ft_move_left(data);
	// if (keysym == 100 || keysym == 65363)
	// 	if (data->map[data->pl_y][data->pl_x + 1] != '1')
	// 		ft_move_right(data);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		calcul_distance(t_data *data)
{
	int	indexX;
	// int	indexY;
	int	i;
	int	x;

	// position du joueur :
	// ft_printf("test du calcul : \ndata x : %d\n", data->player_x);
	// ft_printf("data y : %d\n", data->player_y);
	// calcul de la coordonnee X qui precede le joueur :
	i = 0;
	x = 0;
	indexX = 0;
	// indexY = 0;
	while ((data->player_x - i) % 100 != 0)
		i++;
	// ft_printf("1er intersection data x : %d\n", data->player_x - i);
	// indexX est la correspondance entre le coordonnee et la map (on divise par 100)
	indexX = ((data->player_x - i) / 100) - 1;
	// ft_printf("1er intersection data x : %d\n", indexX);
	while ((data->player_y - x) % 100 != 0)
		x++;
	// ft_printf("1er intersection data y : %d\n", data->player_y - x);
	// indexX est la correspondance entre le coordonnee et la map (on divise par 100)
	// indexY = ((data->player_y - x) / 100) - 1;
	// ft_printf("1er intersection data y : %d\n", indexY);
	
	while (1)
	{		
		// test de chaque coordonnee devant le joueur jusqu'a trouver un mur (1)
		// ft_printf("test avec %c\n", data->map[indexX][data->player_y / 100]);
		if (data->map[indexX][data->player_y / 100] == '1')
		{
			affiche_un_mur(data, i);
			// // debut du mur a taille de l'ecran / 2 - 300
			// data->x = WINDOW_W / 2 - 300;
			// // taille du mur en largeur (axe X)= taille de l'ecran / 2 + 300
			// while ((data->x) < WINDOW_W / 2 + 300)
			// {
			// 	// hauteur du mur commence a : 
			// 	data->y = (WINDOW_H / 2) - (200 / (i / 100));
			// 	// taille du mur en hauteur (axe Y)
			// 	while ((data->y) < WINDOW_H / 2 + (200 / (i / 100)))
			// 	{
			// 		my_mlx_pixel_put(data, data->x, data->y, 0xFF0000);
			// 		data->y++;
			// 	}
			// 	data->x++;
			// }
			// // le (200 / (i / 100)) est la pour changer la hauteur du mur en
			// // fonction de l'eloigement.
			// ft_printf("je renvoie : %d", i);
			return (i);
		}
		indexX--;
		i += 100;
	}
	return (i);	
}

void	affiche_un_mur(t_data *data, int i)
{
	data->x = WINDOW_W / 2 - 300;
	while ((data->x) < WINDOW_W / 2 + 300)
	{
		data->y = WINDOW_H / 2 - (200 / (i / 100));
		while ((data->y) < WINDOW_H / 2 + (200 / (i / 100)))
		{
			my_mlx_pixel_put(data, data->x, data->y, 0xFF0000);
			data->y++;
		}
		data->x++;
	}
}

void	ft_fill_floor(t_data *data)
{
	data->file = mlx_new_image(data->mlx_ptr, data->x, data->y);
	data->addr = mlx_get_data_addr(data->file, &data->bits_per_pixel,
							&data->line_length, &data->endian);
	data->y = 0;
	while ((data->y) < WINDOW_H)
	{
		data->x = 0;
		while ((data->x) < WINDOW_W)
		{
			if (data->y < WINDOW_H / 2)
				my_mlx_pixel_put(data, data->x, data->y, data->color_map_hex_C);
			else
				my_mlx_pixel_put(data, data->x, data->y, data->color_map_hex_F);
			data->x++;
		}
		data->y++;
	}
	// affiche_un_mur(data);
	calcul_distance(data);
	mlx_put_image_to_window (data->mlx_ptr, data->win_ptr, data->file, 
								0, 0);
	mlx_destroy_image(data->mlx_ptr, data->file);
}

int	render(t_data *data)
{
	if (data->win_ptr != NULL)
	{
		if (data->exit == 0)
		{
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			data->win_ptr = NULL;
		}
	}
	return (0);
}

// void	ft_complete_img(t_data *data)
// {
// 	while (1)
// 	{

// 	}
// }

void	ft_create_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_W,
			WINDOW_H, "Zelda");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return ;
	}
	mlx_hook(data->win_ptr, 2, 1L << 0, &handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 1L << 0, &ft_quit, data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	ft_fill_floor(data);
	// ft_complete_img(data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
}
