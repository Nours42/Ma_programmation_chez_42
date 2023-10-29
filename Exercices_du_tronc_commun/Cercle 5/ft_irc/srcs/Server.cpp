/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:02:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/29 19:07:50 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

Server::Server(int port, std::string password) : _port(port), _password(password) {}

Server::~Server() {}

std::string	Server::getPassword(void) const
{
	return (_password);
}

int			Server::getPort(void) const
{
	return (_port);
}

CmdsManager	&Server::getCommands(void)
{
	return (_cmdsManager);
}

ChannelManager	&Server::getChannels(void)
{
	return (_channelManager);
}

UserManager	&Server::getUsers(void)
{
	return (_userManager);
}

void		Server::connect(void)
{
	std::cout << "commande a ecrire" << std::endl;
}
