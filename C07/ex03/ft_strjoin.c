/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 06:09:48 by sdestann          #+#    #+#             */
/*   Updated: 2022/11/15 06:34:24 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	dest_len;
	unsigned int	j;

	dest_len = ft_strlen(dest);
	j = 0;
	while (src[j])
	{
		dest[dest_len + j] = src[j];
		j++;
	}
	dest[dest_len + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		lenght;
	char	*result;

	i = 0;
	lenght = 0;
	while (i < size)
	{
		lenght += ft_strlen(strs[i]);
		i++;
	}
	result = malloc((lenght + (ft_strlen(sep) * size) + 1) * sizeof(char));
	result[0] = '\0';
	i = 0;
	while (i < size)
	{
		result = ft_strcat(result, strs[i]);
		if (i != size - 1)
			result = ft_strcat(result, sep);
		i++;
	}
	return (result);
}
