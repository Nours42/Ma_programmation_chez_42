/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MotdCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:54:50 by nours42           #+#    #+#             */
/*   Updated: 2023/11/02 10:00:31 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../../includes/cmds/MotdCommand.hpp"
#include "../../../includes/Console.hpp"
#include "../../../includes/Message.hpp"

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