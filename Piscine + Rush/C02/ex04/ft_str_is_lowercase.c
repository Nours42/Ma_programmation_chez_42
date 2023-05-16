/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:23:07 by sdestann          #+#    #+#             */
/*   Updated: 2022/11/06 13:23:12 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = str[i];
		if (!((j >= 'a') && (j <= 'z')))
			return (0);
		i++;
	}
	return (1);
}