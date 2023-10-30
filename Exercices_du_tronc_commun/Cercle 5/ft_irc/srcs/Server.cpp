/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:02:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/30 16:00:36 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

Server::Server(int port, std::string password) : _port(port), _password(password)
{
	_cmdsManager.on("KICK", new KickCommand(this));
	_cmdsManager.on("INVITE", new InviteCommand(this));
	_cmdsManager.on("TOPIC", new TopicCommand(this));
	_cmdsManager.on("MODE", new ModeCommand(this));
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

	while (true) {
		FD_ZERO(&readFds);
		FD_SET(_server, &readFds);
		maxSocket = _server;

		for (size_t i = 0; i < _clientSockets.size(); ++i) {
			FD_SET(_clientSockets[i], &readFds);
			maxSocket = std::max(maxSocket, _clientSockets[i]);
		}

		// Multiplexing I/O using select
		select(maxSocket + 1, &readFds, NULL, NULL, NULL);

		if (FD_ISSET(_server, &readFds)) {
			struct sockaddr_in clientAddress;
			socklen_t clientSize = sizeof(clientAddress);
			int newSocket = accept(_server, (struct sockaddr*)&clientAddress, &clientSize);
			_clientSockets.push_back(newSocket);
			Console::log("New client connected");

			// Créez un nouvel objet User ici avec le nouveau socket et l'adresse client
    User* newUser = new User(newSocket, clientAddress);
    // Ajoutez newUser à votre système de gestion des utilisateurs (par exemple, _userManager.add(newUser);)
		}

		for (size_t i = 0; i < _clientSockets.size(); ++i) {
			int clientSocket = _clientSockets[i];
			if (FD_ISSET(clientSocket, &readFds)) {
				char buffer[1024];
				int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);

				if (bytesRead <= 0) {
					Console::log("Client disconnected");
					close(clientSocket);
					_clientSockets.erase(_clientSockets.begin() + i);
					--i; // Adjust index after erasing element
				} else {
					// Handle received data from the client
					buffer[bytesRead] = '\0';
					Console::print("RECEIVED => ", buffer , Console::BLUE);
				}
			}
		}
	}
}