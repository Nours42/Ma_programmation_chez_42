/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:26:19 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/31 11:38:46 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// BIBLIOGRAPHY //

// explication des sockets, setsock, bind, ... :
// https://www.geeksforgeeks.org/socket-programming-cc/ //

#ifndef SERVER_HPP
# define SERVER_HPP

# include <algorithm>
# include <arpa/inet.h>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <iomanip>
# include <iostream>
# include <map>
# include <memory>
# include <netinet/in.h>
# include <sstream>
# include <string>
# include <sys/socket.h>
# include <sys/time.h>
# include <unistd.h>
# include <vector>

class Server;
class User;

# include "Utils.hpp"
# include "Command.hpp"
# include "InviteCommand.hpp"
# include "KickCommand.hpp"
# include "ModeCommand.hpp"
# include "TopicCommand.hpp"
# include "Channel.hpp"
# include "ChannelManager.hpp"
# include "Message.hpp"
# include "CmdsManager.hpp"

# include "Console.hpp"
# include "User.hpp"
# include "UserManager.hpp"



#define PORT 8080

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
		void			connect(void);

		CmdsManager		&getCommands(void);
		ChannelManager	&getChannels(void);
		UserManager		&getUsers(void);
};

#endif