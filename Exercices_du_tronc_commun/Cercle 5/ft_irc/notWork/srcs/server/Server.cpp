/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:18:15 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/26 20:27:37 by nours42          ###   ########.fr       */
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
	struct pollfd fds[64];
    int nfds = 1;
	int client_socket;
    fds[0].fd = _server;
    fds[0].events = POLLIN;
	while (true)
	{
		int pollResult = poll(fds, nfds, -1);
        if (pollResult == -1)
		{
            Console::error("poll");
            break;
        }
        for (int i = 0; i < nfds; ++i)
		{
            if (fds[i].revents & POLLIN)
			{
				//
				std::cout << "(fds[" << i << "].revents & POLLIN)" << std::endl;
				//
				if (fds[i].fd == _server)
                {
					//
					std::cout << "(fds[" << i << "].fd == _server)" << std::endl;
					//
					struct sockaddr_in client_addr;
					socklen_t client_len = sizeof(client_addr);
					client_socket = accept(_server, (struct sockaddr *) &client_addr, &client_len);
					
					if (client_socket < 0)
					{
						//
						std::cout << "(client_socket < 0)" << std::endl;
						//
						Console::error("accept: failed");
					}
					else
					{
						//
						std::cout << "!(client_socket < 0)" << std::endl;
						//
						fcntl(client_socket, F_SETFL, O_NONBLOCK);
						fds[nfds].fd = client_socket;
                        fds[nfds].events = POLLIN;
                        nfds++;
                        Console::print("New client connected!", "OK", Console::GREEN << ON_BLACK << "[SND_BUFFER]");
                        send(client_socket, "PING :Hello\r\n", 13, 0);
					}
				}
				else
				{
					//
					std::cout << "fds[" << i << "].fd != _server" << std::endl;
					//
					char	buffer[1024];
					std::memset(buffer, 0, sizeof(buffer));
					ssize_t received_bytes = recv(fds[i].fd, buffer, sizeof(buffer), 0);
					std::cout << "buffer : " << buffer << std::endl;
					if (received_bytes > 0)
					{
						//
						std::cout << "(received_bytes > 0)" << std::endl;
						//
						if (std::string(buffer) == "\r\n")
						{
							//
							std::cout << "(std::string(buffer) == \"\r\n\")" << std::endl;
							//
							continue;
						}
						if (std::strlen(buffer) > 511)
						{
							//
							std::cout << "(std::strlen(buffer) > 511)" << std::endl;
							//
							send(client_socket, "Limit message to 512 characteres\r\n", 34, 0);
							continue;
						}
						User* user = _userManager.findBySocket(client_socket);
						if (user == NULL)
						{
							//
							std::cout << "(user == NULL)" << std::endl;
							//
							continue;
						}
						if (std::string(buffer).find("\n") == std::string::npos)
						{
							//
							std::cout << "(std::string(buffer).find(\"\n\") == std::string::npos)" << std::endl;
							//
							user->_message += std::string(buffer);
							continue;
						}
						if (user->_message.empty())
						{
							//
							std::cout << "(user->_message.empty())" << std::endl;
							//
							user->_message = std::string(buffer);
						}
						std::cout << "user->message : " << user->_message << std::endl;
						std::vector<std::string> cmd_line = Utils::str_split(user->_message, "\n");
						for (size_t i = 0; i < cmd_line.size(); i++)
						{
							if (cmd_line[i].length() == 0)
							{
								//
								std::cout << "(cmd_line[i].length() == 0)" << std::endl;
								//
								continue;
							}
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
						//
						std::cout << "(received_bytes == 0)" << std::endl;
						//
						Console::error("Erreur 0 bytes recu");
                        close(fds[i].fd);
                        for (int j = i; j < nfds - 1; ++j)
						{
                            fds[j] = fds[j + 1];
                        }
                        nfds--;
						Console::print("Client ", "disconnected", Console::RED);
					}
					else
					{
						//
						std::cout << "(else)" << std::endl;
						//
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
