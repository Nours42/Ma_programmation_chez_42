/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 06:39:16 by sdestann          #+#    #+#             */
/*   Updated: 2022/11/15 06:39:19 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_instr(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkbase(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || ft_instr(base[i], base + i + 1))
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr(unsigned int n, char *base, unsigned int len)
{
	if (n < len)
		ft_putchar(base[n]);
	else
	{
		ft_putnbr(n / len, base, len);
		ft_putchar(base[n % len]);
	}
}

void	ft_putnbr_base(int nb, char *base)
{
	unsigned int	n;
	unsigned int	length;

	length = 0;
	while (base[length])
		length++;
	if (ft_checkbase(base) || length < 2)
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	n = nb;
	ft_putnbr(n, base, length);
}
