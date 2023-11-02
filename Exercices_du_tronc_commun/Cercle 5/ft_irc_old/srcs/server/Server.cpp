/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:02:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/02 11:47:19 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Server.hpp"
#include "../../includes/User.hpp"
#include "../../includes/Console.hpp"
#include "../../includes/cmds/KickCommand.hpp"
#include "../../includes/cmds/InviteCommand.hpp"
#include "../../includes/cmds/TopicCommand.hpp"
#include "../../includes/cmds/ModeCommand.hpp"

Server::Server(int port, std::string password) : _port(port), _password(password)
{
	// creation de la liste de commande possible :
	_cmdsManager.on("KICK", new KickCommand(this));
	_cmdsManager.on("INVITE", new InviteCommand(this));
	_cmdsManager.on("TOPIC", new TopicCommand(this));
	_cmdsManager.on("MODE", new ModeCommand(this));
	//ajout de quelque blabla
	_channelManager.add("#general", "Salon par default pour discuter de tout et de rien.");
	_channelManager.add("#test", "Salon pour effectuer des tests.");
}

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

void Server::processCommand(const std::string& command, const std::string& arguments, int userSocket)
{
	// std::cout << "command : " << command << std::endl;
	std::istringstream iss(arguments);
	std::vector<std::string> args;
	std::string arg;
	while (iss >> arg)
	{
		args.push_back(arg);
	}
	// pour print le vector args :
	// for (std::vector<std::string>::const_iterator it = args.begin(); it != args.end(); ++it) {
	// 	std::cout << *it << std::endl;
	// }
	std::cout << "Server::processCommand userSocket : " << userSocket << std::endl;
	User* user = _userManager.findBySocket(userSocket);
    if (user != NULL)
	{
		std::cout << "command pass : " << command << std::endl;
        _cmdsManager.call(command, args, user);
    }
}

void Server::connect()
{
	_server = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(_port);
	serverAddress.sin_addr.s_addr = INADDR_ANY;

	if (bind(_server, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
		Console::log("bind: error");
		return;
	}

	if (listen(_server, 42) < 0)
		Console::log("listen: error");
	else
		Console::log("Server listening...");

	fd_set readFds;
	int maxSocket;

	while (true)
	{
		size_t	i = 0;
		FD_ZERO(&readFds);
		FD_SET(_server, &readFds);
		maxSocket = _server;

		while (i < _clientSockets.size())
		{
			FD_SET(_clientSockets[i], &readFds);
			maxSocket = std::max(maxSocket, _clientSockets[i]);
			i++;
		}

		select(maxSocket + 1, &readFds, NULL, NULL, NULL);

		if (FD_ISSET(_server, &readFds))
		{
			struct sockaddr_in clientAddress;
			socklen_t clientSize = sizeof(clientAddress);
			int newSocket = accept(_server, (struct sockaddr*)&clientAddress, &clientSize);
			_clientSockets.push_back(newSocket);
			Console::log("New client connected");
		}

		i = 0;
		while (i < _clientSockets.size())
		{
			int clientSocket = _clientSockets[i];
			if (FD_ISSET(clientSocket, &readFds))
			{
				char buffer[1024];
				int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
				if (bytesRead <= 0)
				{
					Console::log("Client disconnected");
					close(clientSocket);
					_clientSockets.erase(_clientSockets.begin() + i);
					--i; // Adjust index after erasing element
				}
				else
				{
					buffer[bytesRead] = '\0';
					Console::print("RECEIVED => ", buffer, Console::BLUE);

					// Analyser la commande et ses arguments
					std::istringstream iss(buffer);
					std::string command, arguments;
					iss >> command >> std::ws;
					std::getline(iss, arguments);

					// Appeler la fonction de traitement des commandes
					processCommand(command, arguments, clientSocket);
				}
			}
			i++;
		}
	}
}

