/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Console.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:17:31 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:17:32 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Console.hpp"
#include "Utils.hpp"

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
