/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:14:36 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/21 14:55:41 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <cstring>
# include <deque>

std::deque<char>	getdeque(std::string input)
{
	std::deque<char> ret;
	int	i = -1;
	
	while (input[++i])
	{
		if (strchr("+-*/ 0123456789", input[i]))
		{
			if (input[i] == ' ')
				continue;
			ret.push_back(input[i]);
		}
		else
		{
			while(!(ret.empty()))
			{
				ret.pop_front();
			}
			break;
		}
	}
	return ret;
}

int	operation(int a, int b, char c)
{
	switch(c)
	{
		case '+':
			return a + b;
		break;
		case '-':
			return a - b;
		break;
		case '*':
			return a * b;
		break;
		case '/':
			return a / b;
		break;
		default:
			return 0;
	}
}

#endif