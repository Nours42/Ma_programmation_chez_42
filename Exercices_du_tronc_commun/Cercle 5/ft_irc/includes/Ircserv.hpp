/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ircserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:26:19 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/28 18:55:45 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// BIBLIOGRAPHY //

// explication des sockets, setsock, bind, ... :
// https://www.geeksforgeeks.org/socket-programming-cc/ //

#ifndef IRCSERV_HPP
# define IRCSERV_HPP

# include <iomanip>
# include <iostream>
# include <algorithm>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <unistd.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>

# include "UserManager.hpp"
# include "ChannelManager.hpp"
# include "CmdsManager.hpp"

#define PORT 8080

int	print_error(std::string str);

class   Server{
	private:
		int         _port;
		std::string _password;

		ChannelManager  _channelManager;
		CmdsManager  _cmdsManager;
		UserManager     _userManager;

	protected:
	public:
		Server(int port, std::string password);
		~Server();
		Server(Server const &ref);
		Server &operator=(Server const &ref);

		std::string	getPassword(void) const;
		int			getPort(void) const;
		void		connect(void);

		CmdsManager		&getCommands(void);
		ChannelManager	&getChannels(void);
		UserManager		&getUsers(void);
};

#endif