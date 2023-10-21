/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/21 15:01:03 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong Use! ./program \"operations\"" << std::endl;
		return (1);
	}

	std::deque<char> mydeque = getdeque(argv[1]);
	if (mydeque.empty())
	{
		std::cerr << "Error" << std::endl;
		return (2);
	}

	int d1, d2;
	std::deque<int> tmp;

	while(!(mydeque.empty()))
	{
		if (isdigit(mydeque.front()))
			tmp.push_back(mydeque.front() - '0');
		else
		{
			d1 = tmp.front(); //front recupere le premier element de la deque (comme un begin())
			tmp.pop_front(); //pop_front retire le premier element de la deque et reduit la taille de celle-ci de 1
			d2 = tmp.front();
			tmp.pop_front();
			tmp.push_front(operation(d1, d2, mydeque.front()));
		}
		mydeque.pop_front();
	}
	std::cout << "Result is : " << tmp.front() << std::endl;
	return (0);
}