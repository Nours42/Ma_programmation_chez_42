/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 08:10:44 by sdestann          #+#    #+#             */
/*   Updated: 2022/11/05 08:52:32 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);
int		ft_wrong_value(int b, int c);

void	ft_print(int F, int a, int b)
{
	ft_putchar(F);
	if (a == b)
		ft_putchar('\n');
}

void	ft_abc(int c1, int c2, int x, int y)
{
	if ((c1 == 0 && c2 == y && y != 0) || (c1 == x && c2 == 0 && x != 0))
	{
		ft_print(92, c1, x);
	}
	else if ((c1 == 0 && c2 == 0) || (c1 == x && c2 == y))
	{
		ft_print(47, c1, x);
	}
	else if (c1 == 0 || c1 == x || c2 == 0 || c2 == y)
	{
		ft_print(42, c1, x);
	}
	else
	{
		ft_putchar(' ');
	}
}

extern	int	rush(int x, int y)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	x = x -1;
	y = y -1;
	ft_wrong_value(x, y);
	while (c2 <= y)
	{
		while (c1 <= x)
		{
			ft_abc(c1, c2, x, y);
			c1++;
		}
		c1 = 0;
		c2++;
	}
	return (0);
}
