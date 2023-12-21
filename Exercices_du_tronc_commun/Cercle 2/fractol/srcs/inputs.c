/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:25:47 by sdestann          #+#    #+#             */
/*   Updated: 2023/12/06 15:25:20 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static inline void	error_msg(int mode)
{
	if (mode == 0)
		ft_printf(ERR_NO_ARGUMENTS);
	else if (mode == 1)
		ft_printf(ERR_FRACTAL_NAME);
	ft_printf("General usage: ./fractol \"graph\"\n\n\
Available graphs:\n\n\
Mandelbrot,\n\n\
Julia (by default),\n\n\
BurningShip,\n\n\
Tricorn\n\n\
You can also set params for Julia set, adding them after the name\n\n\
Example: ./fractol Julia 0.756 -0.1244 (or use \"default\" instead)\n\n\
Advanced usage: ./fractol \"graph\" [x y]/default [r g b]/default\n");
	exit(0);
}

static inline void	input_fractal(char **argv, int *i, t_mlx *mlx, int argc)
{
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		mlx->fractal_type = 1;
	else if (ft_strncmp(argv[1], "Julia", 5) == 0)
		mlx->fractal_type = 2;
	else if (ft_strncmp(argv[1], "BurningShip", 11) == 0)
		mlx->fractal_type = 3;
	else if (ft_strncmp(argv[1], "Tricorn", 11) == 0)
		mlx->fractal_type = 4;
	else
	{
		error_msg(1);
		exit(0);
	}
	if (mlx->fractal_type == 2 && argc > 3)
	{
		if (ft_strncmp(argv[*i], "default", 7) == 0)
			(*i)++;
		else
		{
			mlx->julia_const.re = atof(argv[(*i)++]);
			mlx->julia_const.im = atof(argv[(*i)++]);
		}
	}
}

static inline void	input_colors(char **argv, int *i, t_mlx *mlx, int argc)
{
	if (argc > (*i))
	{
		if (ft_strncmp(argv[*i], "default", 7) == 0)
			(*i)++;
		else if (argc > *i + 2)
		{
			mlx->color_r = abs(ft_atoi(argv[(*i)++])) % 256 + 1;
			mlx->color_g = abs(ft_atoi(argv[(*i)++])) % 256 + 1;
			mlx->color_b = abs(ft_atoi(argv[(*i)++])) % 256 + 1;
		}
	}
}

void	input_handler(int argc, char **argv, t_mlx *mlx)
{
	int	i;

	if (argc < 2)
		error_msg(0);
	i = 2;
	input_fractal(argv, &i, mlx, argc);
	input_colors(argv, &i, mlx, argc);
	ft_printf("\nControl keys:\n\nArrows for moving\n\nMouse wheel or clicks \
for zooming in and out\n\nR key for reset\n\nN key to circle throw graphs\n\n\
Space for color shifting\n\nPlus and Minus keys for zooming with \
static center\n\nL key for making image prettier\n\n\
Also K key for making it worse if possible\n\n");
}
