/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:01:50 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/18 10:58:34 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template< typename T>
void iter(T *array, int array_length, void f(T const &ref))
{
	int i;

	i = 0;
	while (i < array_length)
	{
		f(array[i]);
		i++;
	}		
}

// HELPER FUNCTIONS:
template< typename T>
void	display(T const &t)
{
	std::cout << t << " ";
}

template< typename T>
void ft_tests(T t, int len, std::string type)
{
	std::cout << std::endl << type << std::endl;
	std::cout << "----------------------------" << std::endl;
	iter(t, len, display);
	std::cout << std::endl << std::endl;
}

#endif