/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MotdCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:18:39 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:18:41 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "cmds/MotdCommand.hpp"
#include "Console.hpp"
#include "Message.hpp"

MotdCommand::MotdCommand(Server *server) : _server(server) {};
MotdCommand::~MotdCommand(void) {}

bool	MotdCommand::onCommand(User *sender, std::vector<std::string> args)
{
	(void) args;

	sender->sendMessage(RPL_MOTDSTART, ":- ft_irc Message of the day - ");
	sender->sendMessage(RPL_MOTD, ":- " + _server->getMotd());
	sender->sendMessage(RPL_ENDOFMOTD, ":End of MOTD command");
	return (true);
}
