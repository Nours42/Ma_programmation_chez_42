/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:26:53 by sdestann          #+#    #+#             */
/*   Updated: 2022/11/10 07:34:00 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n > 0)
	{
		i = 0;
		while (s1[i] || s2[i])
		{
			if (s1[i] == s2[i] || i > n - 1)
				i++;
			else
				return (s1[i] - s2[i]);
		}
	}
	return (0);
}