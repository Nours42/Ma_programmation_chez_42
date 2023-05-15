/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:21:41 by sdestann          #+#    #+#             */
/*   Updated: 2022/11/24 08:03:40 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc ((n + 1) * sizeof(char));
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_wcount(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] >= 9 || str[i] <= 13 || str[i] == 32)
			count++;
		i++;
	}
	return (count);
}

int	ft_in_str(char *str, char c)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	char	**exit;
	int		indexw;
	int		indexs;
	int		next;

	indexw = 0;
	indexs = 0;
	if (!str || !charset)
		return (NULL);
	exit = malloc(ft_wcount(str) * sizeof(char *));
	while (str[indexw])
	{
		next = indexw;
		while (!ft_in_str(charset, str[indexw]))
			indexw++;
		if (next != indexw)
		{
			exit[indexs] = ft_strndup(str + next, indexw - next);
			indexs++;
		}
		indexw++;
	}
	exit[indexs] = 0;
	return (exit);
}
