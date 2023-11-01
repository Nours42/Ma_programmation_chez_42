/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:26:19 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/01 14:39:14 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// BIBLIOGRAPHY //

// explication des sockets, setsock, bind, ... :
// https://www.geeksforgeeks.org/socket-programming-cc/ //

#ifndef SERVER_HPP
# define SERVER_HPP

# include <iostream>
# include <cstdlib>
# include <unistd.h>
# include <memory>
# include <errno.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/select.h>
# include <sys/time.h>
# include <fcntl.h>
// # include <sys/event.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>

# include "CmdsManager.hpp"
# include "ChannelManager.hpp"
# include "UserManager.hpp"

/// en test ///

#include <vector>
#include <cstring>
#include <pthread.h>

//////


#define PORT 8080
#define CLIENT_MAX_COUNT	11

int	print_error(std::string str);

class   Server
{
	private:
		Server(Server const &ref);					//no used
		Server &operator=(Server const &ref);		//no used
		
		int							_server;
		char						_opt;
		int         				_port;
		std::string 				_password;
		struct sockaddr_in			_address;
		socklen_t					_addressSize;

		int							_kq;
		std::vector<int>			_clientSockets;

		ChannelManager  			_channelManager;
		CmdsManager  				_cmdsManager;
		UserManager   				  _userManager;

	protected:
	public:
		Server(int port, std::string password);
		~Server();
		

		std::string		getPassword(void) const;
		int				getPort(void) const;
		void			processCommand(const std::string& command, const std::string& arguments, int userSocket);
		void			connect(void);

		CmdsManager		&getCommands(void);
		ChannelManager	&getChannels(void);
		UserManager		&getUsers(void);
};

# include "./cmds/KickCommand.hpp"
# include "./cmds/InviteCommand.hpp"
# include "./cmds/TopicCommand.hpp"
# include "./cmds/ModeCommand.hpp"

#endif