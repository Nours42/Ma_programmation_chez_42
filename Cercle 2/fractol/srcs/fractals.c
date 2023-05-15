/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:39:44 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/25 09:59:18 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(t_complex z, t_mlx mlx)
{
	int			iter;
	double		tmp;
	t_complex	c;

	c.im = z.im;
	c.re = z.re;
	iter = -1;
	while ((pow(z.re, 2) + pow(z.im, 2) < 4) && (++iter < mlx.max_iter))
	{
		tmp = z.re;
		z.re = pow(z.re, 2) - pow(z.im, 2) + c.re;
		z.im = 2 * z.im * tmp + c.im;
	}
	if (iter >= mlx.max_iter)
		return (0x000000);
	return (colorizer(z, iter, mlx));
}

int	julia(t_complex	z, t_mlx mlx)
{
	int			iter;
	double		tmp;

	iter = -1;
	while ((pow(z.re, 2) + pow(z.im, 2) < 4) && (++iter < mlx.max_iter))
	{
		tmp = z.re;
		z.re = pow(z.re, 2) - pow(z.im, 2) + mlx.julia_const.re;
		z.im = 2 * z.im * tmp + mlx.julia_const.im;
	}
	if (iter >= mlx.max_iter)
		return (0x000000);
	return (colorizer(z, iter, mlx));
}

int	burning_ship(t_complex	z, t_mlx mlx)
{
	int			iter;
	double		tmp;
	t_complex	c;

	c.im = z.im;
	c.re = z.re;
	iter = 0;
	while ((pow(z.re, 2) + pow(z.im, 2) < 4) && (iter < mlx.max_iter))
	{
		tmp = z.re;
		z.re = pow(z.re, 2) - pow(z.im, 2) + c.re;
		z.im = fabsl(2 * z.im * tmp) + c.im;
		iter++;
	}
	if (iter >= mlx.max_iter)
		return (0x000000);
	return (colorizer(z, iter, mlx));
}

int	tricorn(t_complex z, t_mlx mlx)
{
	int			iter;
	double		tmp;
	t_complex	c;

	c.im = z.im;
	c.re = z.re;
	iter = 0;
	while ((pow(z.re, 2) + pow(z.im, 2) < 4) && (iter < mlx.max_iter))
	{
		tmp = z.re;
		z.re = pow(z.re, 2) - pow(z.im, 2) + c.re;
		z.im = -2 * z.im * tmp + c.im;
		iter++;
	}
	if (iter >= mlx.max_iter)
		return (0x000000);
	return (colorizer(z, iter, mlx));
}
