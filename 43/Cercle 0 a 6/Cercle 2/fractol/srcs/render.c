/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:32:54 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/24 12:54:59 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	colorizer(t_complex z, int n, t_mlx mlx)
{
	double			a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	a = n + 2 - log(log(z.re * z.re + z.im * z.im)) / M_LN2;
	if (a < 0)
		a = 0;
	a = 8 * sqrt(a);
	r = (int)(floor(a * mlx.color_r)) % 256;
	g = (int)(floor(a * mlx.color_g)) % 256;
	b = (int)(floor(a * mlx.color_b)) % 256;
	return (*(int *)(unsigned char [4]){r, g, b, 0});
}

static inline int	(*choose_fractal(t_mlx mlx))(t_complex z, t_mlx mlx)
{
	if (mlx.fractal_type == 1)
		return (*mandelbrot);
	if (mlx.fractal_type == 2)
		return (*julia);
	if (mlx.fractal_type == 3)
		return (*burning_ship);
	if (mlx.fractal_type == 4)
		return (*tricorn);
	exit(0);
}

void	draw_fractal(t_mlx mlx)
{
	int			x;
	int			y;
	t_complex	z;
	int			(*fractal)(t_complex z, t_mlx mlx);

	fractal = choose_fractal(mlx);
	x = 0;
	y = 0;
	while (++y < WINDOW_H)
	{
		z.im = ((y - WINDOW_H / 2) / mlx.scale + mlx.center_y);
		while (++x < WINDOW_W)
		{
			z.re = ((x - WINDOW_W / 2) / mlx.scale + mlx.center_x);
			mlx.image.data_addr[y * WINDOW_W + x] = fractal(z, mlx);
		}
		x = 0;
	}
}
