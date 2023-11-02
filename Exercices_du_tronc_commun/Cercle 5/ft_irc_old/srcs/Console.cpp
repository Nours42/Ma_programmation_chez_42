/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Console.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:36:49 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/02 10:24:06 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Console.hpp"
#include "../includes/Utils.hpp"

void Console::print(std::string type, std::string str, std::string color)
{
	std::cout << color << " " << type << " " << Console::RESET << " " << Utils::str_trim(str, "\n") << std::endl;
}

void Console::log(std::string str)
{
	Console::print("LOG", str, Console::BLUE);
}

void Console::error(std::string str)
{
	Console::print("ERROR", str, Console::RED);
}