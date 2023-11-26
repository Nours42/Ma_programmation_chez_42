/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:19:37 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/26 20:50:58 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IRC_HPP
# define FT_IRC_HPP

# include <netinet/in.h>
# include <stdio.h>
# include <stdlib.h>
# include <string>
# include <cstring>
# include <sys/socket.h>
# include <unistd.h>
# include <iostream>
# include <arpa/inet.h>
# include <sys/select.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/poll.h>
# include <algorithm>
# include <map>
# include <vector>
# include <stdexcept>
# include <cctype>
# include <iomanip>
# include <csignal>
# include <exception>
# include <stdexcept>
# include <ctime>
# include <sstream>
# include "Color.hpp"

# define RED_LINE	"\033[31m------------------------------------------------------------\033[0m"
# define JOIN   "\033[35m[COMMAND][JOIN]"
# define INVITE	"\033[33m[COMMAND][INVITE]"
# define QUIT	"\033[92m[COMMAND][QUIT] > "
# define DELETE	"\033[31m[DELETE] : "
# define ERROR	"\033[31m[ERROR] : "

# define BUFFSIZE	1024
# define TRUE		1
# define FALSE		0

# define ERR_PASSWDMISMATCH		"464"

# include "Server.hpp"
# include "User.hpp"
# include "Channel.hpp"

//interceptor.cpp
void interpretor(std::string command, int fd, Server * server);
User	*findUser(int fd, Server * server);
void	commands(std::string command, User *user, Server *server);

//commands.cpp
void	join_rmInvit(Channel *channel, User *user);
void	irc_join(std::string message, User *user, Server *server);
void	irc_privmsg(std::string message, User *user, Server *server);
void	irc_part(std::string message, User *user, Server *server);
void	irc_names(Channel *channel, User *user, Server *server);
void	irc_quit(std::string message, User *user, Server *server);
void	irc_nick(std::string message, User *user, Server *server);
void	irc_mode(std::string *message, User *user, Server *server);
void	irc_topic(std::string message, User *user, Server *server);
void	irc_kick(std::string message, User *user, Server *server);
void	irc_invite(std::string message, User *user, Server *server);

//logs.cpp
void	send_log(int & fd, std::string message, Server * server);
void	read_log(int & fd, std::string buffer, Server * server);

#endif
