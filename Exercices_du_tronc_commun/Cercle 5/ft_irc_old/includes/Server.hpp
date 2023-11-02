/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:26:19 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/02 10:31:51 by sdestann         ###   ########.fr       */
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
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
#include <vector>

# include "./UserManager.hpp"
# include "./ChannelManager.hpp"
# include "./CmdsManager.hpp"


#define PORT 8080
#define CLIENT_MAX_COUNT	11

int	print_error(std::string str);

class   Server
{
	private:
		// Server(Server const &ref);					//no used
		// Server &operator=(Server const &ref);		//no used

		int							_port;
		std::string					_password;
		std::string					_opPassword;
		std::string					_motd;
		std::string					_version;
		std::string					_versionComments;
		char						_opt;
		int							_server;
		struct sockaddr_in			_address;
		socklen_t					_addressSize;
		int							_kq;
		std::vector<int>			_clientSockets;

		ChannelManager  			_channelManager;
		CmdsManager  				_cmdsManager;
		UserManager					_userManager;

	protected:
	public:
		Server(int port, std::string password);
		~Server();
		
		/// connect ///

		void			processCommand(const std::string& command, const std::string& arguments, int userSocket);
		void			connect(void);

		///// getters /////
		
		std::string		getMotd(void) const;
		int				getPort(void) const;
		std::string		getPassword(void) const;
		std::string		getOpPassword(void) const;
		std::string		getVersion(void) const;
		std::string		getVersionComments(void) const;
		CmdsManager		&getCommands(void);
		ChannelManager	&getChannels(void);
		UserManager		&getUsers(void);
		
		////// setters //////

		void			setMotd(std::string motd);
		void			setVersion(std::string version);
		void			setVersionComments(std::string comments);
		void			setOpPassword(std::string password);
};

#endif