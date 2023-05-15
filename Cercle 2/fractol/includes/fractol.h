/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:03:23 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/25 11:27:01 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# ifndef WINDOW_H
#  define WINDOW_H 900
# endif
# ifndef WINDOW_W
#  define WINDOW_W 900
# endif
# ifndef INIT_MAX_ITER
#  define INIT_MAX_ITER 100
# endif
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
# define SPACE 32
# define N_KEY 110
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 3
# define WHEEL_DOWN 4
# define WHEEL_UP 5

/*** ERROR MESSAGES ***/

# define ERR_FRACTOL_INIT	"ERROR: Can\'t initialize fractol\n"
# define ERR_WINDOW_INIT	"ERROR: Can\'t initialize window\n"
# define ERR_IMAGE_INIT		"ERROR: Can\'t initialize image\n"
# define ERR_FRACTAL_NAME	"ERROR: No such fractal\n"
# define ERR_NO_ARGUMENTS	"ERROR: No arguments at all\n"

/*	COMPLEX NUMBERS ***/

/* Les nombres complexes sont a la base du calculs des fractales, ils comportent
 une valeur reelle et une valeur imaginaire */

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

/*	IMAGE ***/

/* structure qui gere les images et leurs donnees :
	image			:	image identifier
	data_addr		:	addresse de l'image
	bits_per_pixels	:	profondeur de l'image
	size_line		:	nbr de bits utilises pour stocker une ligne de l'image
	endian			:	little or big endian
*/

typedef struct s_image
{
	void	*image_ptr;
	int		*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_image;

/*	FRACTOL ***/

/* structure qui gere la fractale :
	mlx				:	connection identifier
	window			:	window identifier
	image			:	information about image
	max_iteration	:	maximum iteration
	min				:	minimum real and imaginary parts of complex numbers
	max				:	maximum real and imaginary parts of complex numbers
	factor			:	dependency between complex numbers and pixels
	c				:	complex number
	k				:	constant complex number (only for Julia)
	is_julia_fixed	:	flag that reports Julia is fixed or is not
	start_line		:	start line of fractal part (needed for multi-threading)
	finish_line		:	finish line of fractal part (needed for multi-threading)
	color_shift		:	shift of color channels
	formula			:	fractal formula
	is_help			:	lag that reports help screen is displayed or is not
*/

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	t_image		image;
	int			max_iter;
	int			fractal_type;
	long double	center_x;
	long double	center_y;
	long double	scale;
	int			color_r;
	int			color_g;
	int			color_b;
	t_complex	julia_const;
}				t_mlx;

/*** FUNCTIONS ***/

int		burning_ship(t_complex	z, t_mlx mlx);
int		colorizer(t_complex z, int n, t_mlx mlx);
int		init_params(t_mlx *mlx, char next_frac);
int		julia(t_complex	z, t_mlx mlx);
int		key_controls(int key, t_mlx *mlx);
int		main(int argc, char **argv);
int		mandelbrot(t_complex z, t_mlx mlx);
int		mlx_close(t_mlx *mlx);
int		mouse_controls(int button, int x, int y, t_mlx *mlx);
int		rerender(t_mlx *mlx);
int		tricorn(t_complex z, t_mlx mlx);
void	draw_fractal(t_mlx mlx);
void	input_handler(int argc, char **argv, t_mlx *mlx);
void	set_colors(t_mlx *mlx, int mode);

#endif