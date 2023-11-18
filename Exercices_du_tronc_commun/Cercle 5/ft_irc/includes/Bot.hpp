/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bot.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:30:56 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:32:00 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOT_HPP
#define BOT_HPP

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <memory>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/event.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <vector>

class Bot
{
	private:
		std::string			_host;
		int					_port;
		std::string			_password;
		char				_opt;

		int					_server;
		struct sockaddr_in	_address;
		socklen_t			_addressSize;
		bool				_running;

	public:
		Bot(std::string host, int port, std::string password);
		~Bot(void) { };

		void		connect(std::string channel);
		bool		onCommand(std::string location, std::string name, std::vector<std::string> args);
		bool		reply(std::string location, std::string msg);
		void		stop(void);

		std::string	getHost(void) const;
		int			getPort(void) const;
		std::string	getPassword(void) const;
};

#endif
