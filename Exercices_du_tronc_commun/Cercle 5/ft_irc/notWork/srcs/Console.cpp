/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Console.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:48:43 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:29:41 by nours42          ###   ########.fr       */
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
