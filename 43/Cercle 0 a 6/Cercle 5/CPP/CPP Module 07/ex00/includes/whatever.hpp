/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:14:36 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/18 10:26:42 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template< typename T >

void	swap(T &x, T &y)
{
	T	temp;

	temp = x;
	x = y;
	y = temp;
}

template< typename T >
T const &min(T const &x, T const &y)
{
	return (x<y ? x : y);
}

template< typename T >
T const &max(T const &x, T const &y)
{
	return (x>y ? x : y);
}

template< typename T>
void	ft_print_pair(T a, T b)
{
	std::cout << a << " | " <<  b << std::endl;
}

template< typename T>
void ft_test(T a, T b, std::string type)
{

	std::cout << type << std::endl;
	std::cout << "----------------------------" << std::endl;
	
	// Swap test
	std::cout << "SWAP: " << std::endl;
	std::cout << "Before swapping: \n";
	ft_print_pair(a, b);
	std::cout << "------" << std::endl;
	swap(a, b);
	std::cout << "After swapping: \n";
	ft_print_pair(a, b);
	std::cout << std::endl;

	// Min test
	std::cout << "MIN: " << std::endl;
	std::cout << ::min(a, b) << std::endl << std::endl;

	// Max test	
	std::cout << "MAX: " << std::endl;
	std::cout << ::max(a, b) << std::endl << std::endl;
	std::cout << std::endl << std::endl;
}

#endif