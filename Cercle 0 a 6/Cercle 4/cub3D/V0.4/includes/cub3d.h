/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:06:32 by kaly              #+#    #+#             */
/*   Updated: 2023/09/16 19:06:08 by jmetezea         ###   ########.fr       */
=======
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:03:23 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/14 16:23:12 by sdestann         ###   ########.fr       */
>>>>>>> fc43c40293e881edf2f65252a4cdbe41522467b8
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

<<<<<<< HEAD
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <X11/Xlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include "../libmlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define MLX_ERROR 1

# define PXL 50

# define WINDOW_H 1080
# define WINDOW_W 1920

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	
	char	**map;
	int		index_first_lane;
	int		index_last_lane;

	void	*file;
	char	*addr;
	int		bits_per_pixel;
	int		endian;
	int		size_line;
	int		line_length;

	int			color_r;
	int			color_g;
	int			color_b;

	int		color_map_hex_C;
	int		color_map_hex_F;

	int		player_x;
	int		player_y;
	int		player_orient;
	int		x;
	int		y;

	int		exit;

	// int		pxl;
	// int		map_x;
	// int		map_y;

	// int		pl_move;
	// int		pl_x;
	// int		pl_y;
	// int		player;
	// int		check_collect;
	// int		collect;
	// int		check_exit;

	// int		exit_x;
	// int		exit_y;
	// int		exit_is_open;
}	t_data;

//		break_prog		//

void	ft_clean_when_verif_map_ko(t_data *data);
int		ft_quit(t_data *data);

//		check_arg		//

int	ft_comp_cub(char *arg, char *str);
void	ft_check_arg(int argc, char **argv);

//		error			//

int	err(char *str);
int	err_map(char *str);

//		main			//

void	init_data(t_data *data);
int	main(int argc, char **argv);

//		maps			//

int	color_verif(char *s);
int	fc_validation(char *s, int i);
int	cub_validation(t_data *data);
int	ft_check(int argc, char **argv, t_data *data);


//		print			//

void	titre(char *str);
int	titre_err(char *str);
void	line_up(int i);
void	line(int i);

//		utils			//

char	*make_color_hex(int n);
int	ft_htoi(char *s);
char	*get_map_color(char *s, int l, t_data *data);

//		verif_map		//

int	is_valid_line(char *s);
int	begin_by_one(char *s);
int	ends_by_one(char *s);
int map_validation(t_data *data);

//		verif_player	//

void	player_coordonate(t_data *data);
int	only_one_player(t_data *data);

//		window			//

void	ft_create_window(t_data *data);
void	ft_fill_floor(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		render(t_data *data);
void	ft_complete_img(t_data *data);

#endif
=======
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

// # define ERR_FRACTOL_INIT	"ERROR: Can\'t initialize fractol\n"
// # define ERR_WINDOW_INIT	"ERROR: Can\'t initialize window\n"
// # define ERR_IMAGE_INIT		"ERROR: Can\'t initialize image\n"
# define ERR_FRACTAL_NAME	"ERROR: No such fractal\n"
# define ERR_NO_ARGUMENTS	"ERROR: No arguments at all\n"

/*	IMAGE ***/

/* structure qui gere les images et leurs donnees :
	image			:	image identifier
	data_addr		:	addresse de l'image
	bits_per_pixels	:	profondeur de l'image
	size_line		:	nbr de bits utilises pour stocker une ligne de l'image
	endian			:	little or big endian
*/
typedef struct s_cam
{
	int			speed;
	int			rayposx;
	int			rayposy;
}				t_cam;

typedef struct s_image
{
	void		*image_ptr;
	char		*addr;
	int			*data_addr;
	int			resimgx;
	int			resimgy;
	int			scale;
	int			bits_per_pixel;
	int			endian;
	int			size_line;
	int			line_length;
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
	int			max_iter;
	long double	center_x;
	long double	center_y;
	long double	scale;
	int			color_r;
	int			color_g;
	int			color_b;
	int			x;
	int			y;
	int			pxl;
}				t_mlx;

typedef struct s_map
{
	int		player_coord[2];
	int		player_start_orient;
	int		player_see;
	char	**map;
	int		color_map_hex_C;
	int		color_map_hex_F;
	int		ligne_zero;
	int		ligne_max;
	int		longueur_de_ligne[100];
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
void	ft_clean_when_verif_map_ko(t_data *data);
void	ft_clean_all(t_data *data);


// main.c

int		mlx_close(t_data *data);
int		init_params(t_data *data);
int		rerender(t_data *data);
int		main(int argc, char **argv);

// maps.c

int		color_verif(char *s);
int		fc_validation(char *s, int i);
int		cub_validation(t_data *data);
int		ft_check(int argc, char **argv, t_data *data);

// print.c


void	titre(char *str);
int		titre_err(char *str);
void	line_up(int i);
void	line(int i);

// utils.c

char	*make_color_hex(int n);
int		ft_htoi(char *s);
char	*get_map_color(char *s, int l, t_data *data);

// verif_map.c

int		is_valid_line(char *s);
int		begin_by_one(char *s);
int		ends_by_one(char *s);
int		map_validation(t_data *data);
int		where_s_the_wall(int x, int y, int angle, t_data *data);
void	test_gps(t_data *data);

// verif_player.c

void	player_coordonate(t_data *data);
int		player_can_moove(t_data *data);
int		only_one_player(t_data *data);

#endif
>>>>>>> fc43c40293e881edf2f65252a4cdbe41522467b8
