/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:03:23 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/11 13:01:17 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef WINDOW_H
#  define WINDOW_H 900
# endif

# ifndef WINDOW_W
#  define WINDOW_W 900
# endif

// # ifndef INIT_MAX_ITER
// #  define INIT_MAX_ITER 100
// # endif

# ifndef SCALE_FACTOR
#  define SCALE_FACTOR 1.25
# endif

# ifndef SCALE_ITER
#  define SCALE_ITER 10
# endif

# ifndef MOVING_FACTOR
#  define MOVING_FACTOR 200
# endif

/*** LIBRAIRIES ***/

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libmlx/mlx.h"
# include "../libmlx/mlx_int.h"

/*** KEYBOARD && MOUSE***/

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define PLUS 65451
# define MINUS 65453

# define R_KEY 114
# define L_KEY 108
# define K_KEY 107
# define N_KEY 110

# define SPACE 32

# define MOUSE_LEFT 1
# define MOUSE_RIGHT 3
# define WHEEL_DOWN 4
# define WHEEL_UP 5

/*** ERROR MESSAGES ***/

# define ERR_FRACTAL_NAME	"ERROR: No such fractal\n"
# define ERR_NO_ARGUMENTS	"ERROR: No arguments at all\n"

typedef struct s_cam
{
	int			speed;
	int			rayposx;
	int			rayposy;
}				t_cam;

typedef struct s_image
{
	void		*image_ptr;
	int			*data_addr;
	int			resimgx;
	int			resimgy;
	int			scale;
	int			bits_per_pixel;
	int			endian;
	int			size_line;
}				t_image;

// les bits_per_pixel, endian et size_line ne sont peut-etre pas utiles a voir

typedef struct s_mouse
{
	double		center_x;
	double		center_y;
}				t_mouse;

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
}				t_mlx;

typedef struct s_map
{
	int		coord[2];
	char	**map;
}				t_map;

typedef struct t_data
{
	t_cam		*cam;
	t_image		*image;
	t_map		*map;
	t_mlx		*mlx;
	t_mouse		*mouse;
}				t_data;

/*** FUNCTIONS ***/

// control.c

void	moving(int key, t_data *data);
int		key_controls(int key, t_data *data);
int		mouse_controls(int button, int x, int y, t_data *data);

// error.c

int		err(char *str);
int		err_map(char *str);

// game_over.c

void	game_over(t_data *data);
void	ft_clean_all(t_data *data);

// main.c

int		mlx_close(t_data *data);
int		init_params(t_data *data);
int		rerender(t_data *data);
int		main(int argc, char **argv);

// maps.c

int		color_verif(char *s);
int		fc_validation(char *s, int i);
int		cub_validation(t_map	*cub);
int		ft_check(int argc, char **argv, t_map *cub);
int		ft_check2(t_map *cub);

// print.c

void	titre(char *str);
void	titre2(char *str, int i);
int		titre_err(char *str);
void	line_up(int i);
void	line(int i);

// verif_map.c

int		is_valid_line(char *s);
int		begin_by_one(char *s);
int		ends_by_one(char *s);
int		map_validation(t_map *cub);
int		ft_cub(char *argv);

// verif_player.c

void	player_coordonate(t_map *cub);
int		player_can_moove(t_map *cub);
int		only_one_player(t_map *cub);

#endif