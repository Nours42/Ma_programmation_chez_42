/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logs.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:20:26 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/22 22:11:12 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_irc.hpp"

void	send_log(int & fd, std::string message, Server * server)
{
	std::vector<User *>::iterator	it = server->users.begin();
	std::vector<User *>::iterator	ite = server->users.end();
	std::string						name;
	//char *							string = strdup(message);

	//string = strtok(string, "\r\n");
	std::stringstream ss(message);

    std::string line;
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
	//free(string);
}

void	read_log(int &fd, std::string buffer, Server * server)
{
	std::vector<User *>::iterator	it = server->users.begin();
	std::vector<User *>::iterator	ite = server->users.end();
	std::string						name;
	ssize_t pos = buffer.find('\r');
	std::string line = buffer.substr(0, pos);
	while (it != ite && name.empty())
	{
		if (fd == (*it)->fd)
			name = (*it)->nickname;
		it++;
	}
	if (it == ite)
		std::cout << CYAN << "[" << fd << " - new user] : ";
	else
		std::cout << CYAN << "[" << fd << " - " << name << "] : ";
	std::cout << line << RESET << std::endl;
}