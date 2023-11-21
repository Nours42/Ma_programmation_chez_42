/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:20:29 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:20:30 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <stdlib.h>

std::vector<std::string> split(std::string str, char delimiter)
{
	std::stringstream ss(str);
	std::vector<std::string> tokens;

	std::string token;
	while (std::getline(ss, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

std::string intToString(int num)
{
	std::ostringstream ss;
	ss << num;
	return (ss.str());
}

int randInt(int min, int max)
{
	return (rand() % (max - min + 1) + min);
}

bool containsOnlyDigits(const std::string &str)
{
	return str.find_first_not_of("0123456789") == std::string::npos;
}
