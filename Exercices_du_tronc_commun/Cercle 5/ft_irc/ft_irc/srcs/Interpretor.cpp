/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interpretor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:20:19 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/25 20:47:19 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_irc.hpp"

User	*findUser(int fd, Server * server)
{
	for (std::vector<User *>::iterator it = server->users.begin(); it != server->users.end(); ++it)
	{
		if ((*it)->fd == fd)
			return (*it);
	}
	return NULL;
}

void commands(std::string message, User *user, Server *server) {
    if (message.compare(0, 4, "JOIN") == 0)
        irc_join(message, user, server);
    else if (message.compare(0, 7, "PRIVMSG") == 0)
        irc_privmsg(message, user, server);
    else if (message.compare(0, 4, "PING") == 0) {
        std::cout << COMMAND << "PING" << std::endl;
        std::string rpl_pong = "PONG " + message.substr(5) + "\r\n";
        send(user->fd, rpl_pong.c_str(), rpl_pong.length(), 0);
        send_log(user->fd, rpl_pong, server);
    } else if (message.compare(0, 4, "PART") == 0)
        irc_part(message, user, server);
    else if (message.compare(0, 4, "MODE") == 0)
        irc_mode(&message, user, server);
    else if (message.compare(0, 4, "QUIT") == 0)
        irc_quit(message, user, server);
    else if (message.compare(0, 4, "NICK") == 0)
        irc_nick(message, user, server);
    else if (message.compare(0, 5, "TOPIC") == 0)
        irc_topic(message, user, server);
    else if (message.compare(0, 4, "KICK") == 0)
        irc_kick(message, user, server);
    else if (message.compare(0, 6, "INVITE") == 0)
        irc_invite(message, user, server);
    else {
        std::string rpl_error = ":127.0.0.1 421 " + user->nickname + " :Unknown command\r\n";
        send(user->fd, rpl_error.c_str(), rpl_error.length(), 0);
        send_log(user->fd, rpl_error, server);
    }
}

//void	interpretor(char *message, int fd, Server * server)
//{
//	User *user = findUser(fd, server);
//	if (user == NULL)
//	{
//		std::cout << "[ERROR] : User not found" << std::endl;
//		return ;
//	}
//	if (message[0] >= 'A' && message[0] <= 'Z')
//		commands(message, user, server);
//}

void interpretor(std::string message, int fd, Server *server) {
    User *user = findUser(fd, server);
    if (user == NULL) {
        std::cout << "[ERROR] : User not found" << std::endl;
        return;
    }
    if (message[0] >= 'A' && message[0] <= 'Z')
        commands(message, user, server);
}
