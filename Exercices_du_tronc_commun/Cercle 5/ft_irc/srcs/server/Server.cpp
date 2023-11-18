/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:02:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/07 11:35:03 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Server::Server(int port, std::string password) : _port(port), _password(password)
//{
//	si server n'existe pas :
//		cree un User.
//		cree un channel general dont le user est modo.
//		dit bienvenue
//	tente de rejoindre le server avec le password.
//		si non, "wrong password"
//		si oui, cree un User.
//		ajoute l'User a general en user simple.
//		dit bienvenue
//}

//Server::~Server() {} 

//std::string	Server::getPassword(void) const
//{
//	return (_password);
//}

//int	Server::getPort(void) const
//{
//	return (_port);
//}

//Channel	&Server::getChannels(void)
//{
//	return (_channel);
//}

//User	&Server::getUsers(void)
//{
//	return (_user);
//}

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
=======
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:57:50 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:29:44 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Utils.hpp"
#include "Console.hpp"
#include "User.hpp"

#include "cmds/PassCommand.hpp"
#include "cmds/UserCommand.hpp"
#include "cmds/NickCommand.hpp"
#include "cmds/JoinCommand.hpp"
#include "cmds/PrivmsgCommand.hpp"
#include "cmds/QuitCommand.hpp"
#include "cmds/TopicCommand.hpp"
#include "cmds/ModeCommand.hpp"
#include "cmds/PingCommand.hpp"
#include "cmds/PartCommand.hpp"
#include "cmds/MotdCommand.hpp"
#include "cmds/VersionCommand.hpp"
#include "cmds/TimeCommand.hpp"
#include "cmds/InviteCommand.hpp"
#include "cmds/OperCommand.hpp"
#include "cmds/ListCommand.hpp"
#include "cmds/KickCommand.hpp"
#include "cmds/NamesCommand.hpp"

Server::Server(int port, std::string password) : _port(port), _password(password)
{
	// TODO: #4 Hash the password for more security

	setVersion("1.0");											// version du serveur
	setVersionComments("Premiere version public du server.");	// commentaire de la version
	setMotd("Le meilleur serveur irc de 42!");					// message du jour
	setOpPassword("operator");									// mot de passe des operators

	_cmdsManager.on("PASS", new PassCommand(this));
	_cmdsManager.on("USER", new UserCommand());
	_cmdsManager.on("NICK", new NickCommand(this));
	_cmdsManager.on("JOIN", new JoinCommand(this));
	_cmdsManager.on("PRIVMSG", new PrivmsgCommand(this));
	_cmdsManager.on("NOTICE", new PrivmsgCommand(this));
	_cmdsManager.on("QUIT", new QuitCommand(this));
	_cmdsManager.on("TOPIC", new TopicCommand(this));
	_cmdsManager.on("MODE", new ModeCommand(this));
	_cmdsManager.on("PING", new PingCommand());
	_cmdsManager.on("PART", new PartCommand(this));
	_cmdsManager.on("MOTD", new MotdCommand(this));
	_cmdsManager.on("VERSION", new VersionCommand(this));
	_cmdsManager.on("TIME", new TimeCommand(this));
	_cmdsManager.on("INVITE", new InviteCommand(this));
	_cmdsManager.on("OPER", new OperCommand(this));
	_cmdsManager.on("LIST", new ListCommand(this));
	_cmdsManager.on("KICK", new KickCommand(this));
	_cmdsManager.on("NAMES", new NamesCommand(this));

	_channelManager.add("#general", "Salon par default pour discuter de tout et de rien.");
	_channelManager.add("#test", "Salon pour effectuer des tests.");
}

Server::~Server(void) {}

void Server::connect(void)
>>>>>>> 80cc973 (ft_irc)
{
	_server = socket(AF_INET, SOCK_STREAM, 0);
	_opt = 1;

	setsockopt(_server, SOL_SOCKET, SO_REUSEADDR, &_opt, sizeof(int));

	std::memset((char*) &_address, 0, sizeof(_address));
	_address.sin_family			=	AF_INET;
	_address.sin_port			=	htons(_port);
	_address.sin_addr.s_addr	=	htons(INADDR_ANY);

	if (bind(_server, (struct sockaddr *) &_address, sizeof(_address)) < 0)
		Console::log("bind: error");
	fcntl(_server, F_SETFL, O_NONBLOCK);
	if (listen(_server, 42) < 0)
		Console::log("listen: error");
	struct pollfd fds[1];
    fds[0].fd = _server;
    fds[0].events = POLLIN;
	Console::log("Server listening...");
	_addressSize = sizeof(_address);
	while (true)
	{
		int pollResult = poll(fds, 1, -1);
        if (pollResult == -1)
		{
            Console::error("poll");
            break;
        }
        if (pollResult > 0)
		{
            if (fds[0].revents & POLLIN)
			{
                struct sockaddr_in client_addr;
                socklen_t client_len = sizeof(client_addr);
                int client_socket = accept(_server, (struct sockaddr *) &client_addr, &client_len);
                if (client_socket < 0)
				{
                    Console::error("accept: failed");
				}
				else
				{
					fcntl(client_socket, F_SETFL, O_NONBLOCK);
					_userManager.add(new User(client_socket, client_addr));
					send(client_socket, "PING :Hello\r\n", 13, 0);
				}
				if (fds[0].fd == client_socket)
				{
				char	buffer[1024];
				std::memset(buffer, 0, 1024);
				ssize_t received_bytes = recv(client_socket, buffer, sizeof(buffer), 0);
					if (received_bytes > 0)
					{
						if (std::string(buffer) == "\r\n")
						{
							continue;
						}
						if (std::strlen(buffer) > 511)
						{
							send(client_socket, "Limit message to 512 characteres\r\n", 34, 0);
							continue;
						}
						User* user = _userManager.findBySocket(client_socket);
						if (user == NULL)
						{
							continue;
						}
						if (std::string(buffer).find("\n") == std::string::npos)
						{
							user->_message += std::string(buffer);
							continue;
						}
						if (user->_message.empty())
						{
							user->_message = std::string(buffer);
						}
						std::vector<std::string> cmd_line = Utils::str_split(user->_message, "\n");
						for (size_t i = 0; i < cmd_line.size(); i++)
						{
							if (cmd_line[i].length() == 0)
								continue;
							Console::print("=> RECEIVED", cmd_line[i], Console::BLUE);
							std::vector<std::string> cmd_args = Utils::str_parse(cmd_line[i]);
							for (size_t j = 0; j < cmd_args.size(); j++)
								cmd_args[j] = Utils::str_trim(cmd_args[j], " \n\t\r\f\v");
							std::string cmd_name = Utils::str_trim(cmd_args[0], " \n\t\v\f\r");
							_cmdsManager.call(cmd_name, cmd_args, user);
						}
						user->_message.clear();
					} 
					else if (received_bytes == 0)
					{
						
					}
					else
					{
						// Erreur de réception
						Console::error("recv: error");
					}
				}
			}
		}
	}
	close(_server);
	Console::log("Server stopped...");
}

int Server::getPort(void) const
{ return _port; }

std::string Server::getPassword(void) const
{ return _password; }

std::string Server::getMotd(void) const
{ return _motd; }

void Server::setMotd(std::string motd)
{ _motd = motd; }

std::string Server::getVersion(void) const
{ return _version; }

void Server::setVersion(std::string version)
{ _version = version; }

std::string Server::getVersionComments(void) const
{ return _versionComments; }

void Server::setVersionComments(std::string comments)
{ _versionComments = comments; }

std::string Server::getOpPassword(void) const
{ return _opPassword; }

void Server::setOpPassword(std::string password)
{ _opPassword = password; }

CommandManager&	Server::getCommands(void) { return _cmdsManager; }
ChannelManager&	Server::getChannels(void) { return _channelManager; }
UserManager&	Server::getUsers(void) { return _userManager; }
