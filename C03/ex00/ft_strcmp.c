/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:26:53 by sdestann          #+#    #+#             */
/*   Updated: 2022/11/10 20:46:24 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
		printf("je suis dans la boucle est, la valeur de s1 est %d la valeur de s2 est %d\n", s1[i], s2[i]);

	}
	printf("la valeur de s1 est %d la valeur de s2 est %d\n", s1[i], s2[i]);
	return (s1[i] - s2[i]);
}

int	ft_strcmp(char *s1, char *s2);

int main(void)
{
	printf("%d\n", ft_strcmp("-2", "-1"));
	//printf("%d\n", ft_strcmp("bbjbs55gzl", "bbj"));
	//printf("%d\n", ft_strcmp("bb", "bbjhxzfkjhabs"));
	//printf("%d\n", ft_strcmp("aab", "\0"));
	
	return (0);
}
