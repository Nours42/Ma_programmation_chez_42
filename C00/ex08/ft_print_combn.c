/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:32:30 by sdestann          #+#    #+#             */
/*   Updated: 2022/11/05 21:32:36 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check(int nb, int n)
{
	if (nb == 9 && n == 1)
		return (1);
	if (nb == 89 && n == 2)
		return (1);
	if (nb == 789 && n == 3)
		return (1);
	if (nb == 6789 && n == 4)
		return (1);
	if (nb == 56789 && n == 5)
		return (1);
	if (nb == 456789 && n == 6)
		return (1);
	if (nb == 3456789 && n == 7)
		return (1);
	if (nb == 23456789 && n == 8)
		return (1);
	if (nb == 123456789 && (n == 9 || n == 10))
		return (1);
	else
		return (0);
}

void	ft_putnbr(int nb, int n)
{
	int	x;

	x = nb % 10 + 48;
	if (n > 1)
	{
		nb = nb / 10;
		ft_putnbr(nb, n - 1);
		write(1, &x, 1);
	}
	else
	{
		nb = nb + 48;
		write(1, &nb, 1);
	}
}

void	ft_write(int nb, int n)
{
	if (ft_check(nb, n) != 1)
	{
		ft_putnbr(nb, n);
		write(1, ", ", 2);
	}
	else
	{
		ft_putnbr(nb, n);
		return ;
	}
}

void	ft_recursive(int n, int a, int sum, int i)
{
	if (n != 0)
	{
		while (a <= 9)
		{
			ft_recursive(n - 1, a + 1, sum * 10 + a, i);
			a++;
		}
	}
	else
	{
		ft_write(sum, i);
	}
}

void	ft_print_combn(int n)
{
	ft_recursive(n, 0, 0, n);
}
