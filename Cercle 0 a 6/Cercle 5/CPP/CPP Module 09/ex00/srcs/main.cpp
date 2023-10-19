/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:22:07 by nours42           #+#    #+#             */
/*   Updated: 2023/10/19 15:51:26 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	std::queue<amount>		myQueue;
	amount					tmp;

	if (argc != 2)
	{
		std::cerr << "Wrong Use! ./program <input file>" << std::endl;
		return (1);
	}
	myQueue = tmp.getqueue(argv[1]);
	while (!myQueue.empty())
	{
		tmp = myQueue.front();
		if (tmp.getvalue() == -1)
			std::cout << tmp.getdate() << std::endl;
		else
			std::cout << tmp.getdate() << " => " << tmp.getvalue() << " = " << tmp.getvalue() * 18 << std::endl;
		myQueue.pop();
	}
}