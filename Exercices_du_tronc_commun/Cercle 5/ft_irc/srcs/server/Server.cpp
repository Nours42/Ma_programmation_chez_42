/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:02:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/01 14:12:20 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

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

// void Server::connect(void) // ancienne version avec event.h
// {
// 	_server = socket(AF_INET, SOCK_STREAM, 0);
// 	_opt = 1;

// 	setsockopt(_server, SOL_SOCKET, SO_REUSEADDR, &_opt, sizeof(int));

// 	std::memset((char*) &_address, 0, sizeof(_address));
// 	_address.sin_family			=	AF_INET;
// 	_address.sin_port			=	htons(_port);
// 	_address.sin_addr.s_addr	=	htons(INADDR_ANY);

// 	if (bind(_server, (struct sockaddr *) &_address, sizeof(_address)) < 0)
// 		Console::log("bind: error");

// 	fcntl(_server, F_SETFL, O_NONBLOCK);

// 	if (listen(_server, 42) < 0)
// 		Console::log("listen: error");

// 	_changes.resize(1);
// 	if ((_kq = kqueue()) == -1)
// 		Console::log("kqueue: failed init");

// 	EV_SET(_changes.begin().base(), _server, EVFILT_READ, EV_ADD, 0, 0, 0);

// 	Console::log("Server listening...");

// 	_addressSize = sizeof(_address);
// 	while (true)
// 	{
// 		_events.clear();
// 		_events.resize(1);
// 		int newEvents = kevent(
// 			_kq,
// 			_changes.begin().base(), _changes.size(),
// 			_events.begin().base(), _events.size(), NULL
// 		);
// 		if (newEvents < 0)
// 		{
// 			Console::error("kevent: error");
// 			break;
// 		}
// 		_changes.clear();

// 		for (int i = 0; i < newEvents; i++)
// 		{
// 			int event_fd = _events[i].ident;

// 			if (_events[i].flags & EV_ERROR)
// 				Console::error("kevent: EV_ERROR");
// 			if (_events[i].flags & EV_EOF)
// 			{
// 				User* user = _userManager.findBySocket(event_fd);
// 				if (user != NULL)
// 					_cmdsManager.call("QUIT", std::vector<std::string>(), user);
// 			}
// 			else if (event_fd == _server)
// 			{
// 				struct sockaddr_in client_addr;
// 				socklen_t client_len = sizeof(client_addr);
// 				int socket = accept(event_fd, (struct sockaddr *) &client_addr, &client_len);
// 				if (socket < 0)
// 					Console::error("accept: failed");

// 				_changes.resize(_changes.size() + 1);
// 				fcntl(socket, F_SETFL, O_NONBLOCK);
// 				EV_SET(_changes.end().base() - 1, socket, EVFILT_READ, EV_ADD, 0, 0, 0);

// 				_userManager.add(new User(socket, client_addr));

// 				_events.resize(_events.size() + 1);
// 				send(socket, "PING :Hello\r\n", 13, 0);
// 			}
// 			else if (_events[i].filter & EVFILT_READ)
// 			{
// 				char	buffer[1024];
// 				std::memset(buffer, 0, 1024);
// 				recv(event_fd, buffer, 1024, 0);

// 				if (std::string(buffer) == "\r\n")
// 					continue;

// 				if (std::strlen(buffer) > 511)
// 				{
// 					send(event_fd, "Limit message to 512 characteres\r\n", 34, 0);
// 					continue;
// 				}

// 				User* user = _userManager.findBySocket(event_fd);
// 				if (user == NULL)
// 					continue;

// 				if (std::string(buffer).find("\n") == std::string::npos)
// 				{
// 					user->_message += std::string(buffer);
// 					continue;
// 				}

// 				if (user->_message.empty())
// 					user->_message = std::string(buffer);

// 				std::vector<std::string> cmd_line = Utils::str_split(user->_message, "\n");
// 				for (size_t i = 0; i < cmd_line.size(); i++)
// 				{
// 					if (cmd_line[i].length() == 0)
// 						continue;

// 					Console::print("=> RECEIVED", cmd_line[i], Console::BLUE);

// 					std::vector<std::string> cmd_args = Utils::str_parse(cmd_line[i]);
// 					for (size_t j = 0; j < cmd_args.size(); j++)
// 						cmd_args[j] = Utils::str_trim(cmd_args[j], " \n\t\r\f\v");
// 					std::string cmd_name = Utils::str_trim(cmd_args[0], " \n\t\v\f\r");
// 					_cmdsManager.call(cmd_name, cmd_args, user);
// 				}
// 				user->_message.clear();
// 			}
// 		}
// 	}
// 	close(_server);

// 	Console::log("Server stopped...");
// }

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

