/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:15:17 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 16:41:38 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <cstdlib>

#include <unistd.h>
#include <memory>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
// #include <sys/event.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
// ajout
#include <cstring>
#include <poll.h>
//
#include "CommandManager.hpp"
#include "ChannelManager.hpp"
#include "UserManager.hpp"

#define CLIENT_MAX_COUNT	11

class Server
{
	private:
		int							_port;
		std::string					_password;
		std::string					_opPassword;
		std::string					_motd;
		std::string					_version;
		std::string					_versionComments;

		char						_opt;
		int							_server;
		struct sockaddr_in			_address;
		//socklen_t					_addressSize;

		// int							_kq;
		// std::vector<struct kevent>	_changes;
		// std::vector<struct kevent>	_events;

		CommandManager				_cmdsManager;
		ChannelManager				_channelManager;
		UserManager					_userManager;

	public:
		Server(int port, std::string password);
		~Server(void);

		void 			connect(void);

		std::string		getMotd(void) const;
		void			setMotd(std::string motd);
		std::string		getVersion(void) const;
		void			setVersion(std::string version);
		std::string		getVersionComments(void) const;
		void			setVersionComments(std::string comments);
		void			setOpPassword(std::string password);

		int				getPort(void) const;
		std::string		getPassword(void) const;
		std::string		getOpPassword(void) const;
		CommandManager&	getCommands(void);
		ChannelManager&	getChannels(void);
		UserManager&	getUsers(void);

};

#endif
