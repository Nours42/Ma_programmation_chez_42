/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:25:29 by sdestann          #+#    #+#             */
/*   Updated: 2022/11/09 11:57:30 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[i] == 0)
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while ((to_find[j] == str[i + j]) || to_find[j] == '\0')
			{
				if (to_find[j] == '\0')
				{
					return (&str[i]);
				}
				j++;
			}
		}
		i++;
	}
	return (0);
}
