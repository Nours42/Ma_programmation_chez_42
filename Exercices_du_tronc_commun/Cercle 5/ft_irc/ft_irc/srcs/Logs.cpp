/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logs.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:20:26 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/25 20:47:24 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_irc.hpp"

void	send_log(int & fd, std::string message, Server * server)
{
	std::vector<User *>::iterator	it = server->users.begin();
	std::vector<User *>::iterator	ite = server->users.end();
	std::string						name;
	std::stringstream 				ss(message);
    std::string 					line;

    std::getline(ss, line, '\n');
	while (it != ite && name.empty())
	{
		if (fd == (*it)->fd)
			name = (*it)->nickname;
		it++;
	}
	std::cout << GREEN;
	if (name.empty())
		std::cout << "[" << fd << " - new user] : ";
	else
		std::cout << "[" << fd << " - " << name << "] : ";
	std::cout << line << RESET << std::endl;
}

void	read_log(int & fd, std::string buffer, Server * server)
{
	std::vector<User *>::iterator	it = server->users.begin();
	std::vector<User *>::iterator	ite = server->users.end();
	std::string						name;
	std::stringstream				ss(buffer);
    std::string						line;
	
    std::getline(ss, line, '\n');
	while (it != ite && name.empty())
	{
		if (fd == (*it)->fd)
			name = (*it)->nickname;
		it++;
	}
	std::cout << CYAN;
	if (name.empty())
		std::cout << "[" << fd << " - new user] : ";
	else
		std::cout << "[" << fd << " - " << name << "] : ";
	std::cout << buffer << RESET << std::endl;
}