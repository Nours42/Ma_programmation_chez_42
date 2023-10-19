/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/18 16:53:18 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <iomanip>

int main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// test better //

	Span	sp1(1, 10, 1);
	std::cout << sp1;
	std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << sp1.longestSpan() << std::endl;

	Span	sp2(1, 2000000, 10);
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << sp2.longestSpan() << std::endl;

	Span	sp3 = Span(30);
	std::vector<int>	a;
	my_iter				b;
	my_iter				c;
	a = sp1.getVector();
	b = a.begin();
	c = a.end();
	
	sp3.addNumber(b, c);
	sp3.addNumber(b, c);
	std::cout << sp3;
	std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << sp3.longestSpan() << std::endl;
	
	Span	sp4(0);
	std::cout << sp4;
	try
	{
		sp4.addNumber(5);
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		sp4.shortestSpan();
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		sp4.longestSpan();
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
