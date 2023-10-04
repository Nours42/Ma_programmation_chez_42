/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:35:20 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/04 18:21:39 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

void	print_128(char **res)
{
	int	i;
	int	fd;
	char c;

	i = 0;
	fd = 0;
	while (res[i])
	{
		while (res[i][fd])
		{
			c = res[i][fd];
			// if (c < -64)
			// 	ft_printf("%d ", (c + 128));
			// else if (c <= 0)
			// 	ft_printf("%d ", (c + 64));
			// else if (c > 64)
			// 	ft_printf("%d ", (c - 64));
			// else
			ft_printf("%d ", c);
			fd++;
		}
		i++;
	}
}

void	min_max(char **res)
{
	int	i;
	int	fd;
	int	min;
	int	max;
	int	c;

	i = 0;
	fd = 0;
	min = 100000;
	max = -100000;
	while (res[i])
	{
		while (res[i][fd])
		{
			c = res[i][fd];
			if (c < min)
			{
				ft_printf("min a changé par : %d\n", c);
				min = c;
			}
			if (c > max)
			{
				ft_printf("max a changé par : %d\n", c);
				max = c;
			}
			fd++;
		}
		i++;
	}
	ft_printf("min final : %d\n", min);
	ft_printf("max final : %d\n", max);
}

void    boucle(char **res, char **argv)
{
	int		i;
	int		fd;
	char	*s;
	char	c;

	res = (char **)malloc(sizeof(char) * 10000);
	fd = open(argv[1], O_RDONLY);
	if (fd < 1)
		write(2, "error fd\n", 9);
	s = get_next_line(fd);
	i = 0;
	while (s)
	{
		res[i++] = ft_strdup(s);
		free(s);
		s = get_next_line(fd);
	}
	res[i] = 0;
	min_max(res);
	print_128(res);
}

int main(int argc, char **argv)
{
	char	**res;
	int		i;

	if (argc >= 1)
	{
		boucle(res, argv);
		i = 0;
		// while (res[i])
		// {
		// 	free(res[i]);
		// 	i++;
		// }
		// free(res);
	}
	return (0);
}