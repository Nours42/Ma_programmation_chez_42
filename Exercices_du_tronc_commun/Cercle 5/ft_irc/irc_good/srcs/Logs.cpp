/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logs.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:44:56 by rrodor            #+#    #+#             */
/*   Updated: 2023/11/22 10:33:48 by sdestann         ###   ########.fr       */
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

void	read_log(int & fd, std::string buffer, Server * server)
{
	std::vector<User *>::iterator	it = server->users.begin();
	std::vector<User *>::iterator	ite = server->users.end();
	std::string						name;

	//buffer = strtok(buffer, "\r\n");
	std::stringstream ss(buffer);

    std::string line;
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