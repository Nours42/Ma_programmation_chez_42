/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PingCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:56:31 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 16:31:11 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "Console.hpp"
#include "../../../includes/cmds/PingCommand.hpp"

PingCommand::PingCommand(Server *server) : _server(server) {}
PingCommand::~PingCommand(void) {}

bool PingCommand::onCommand(User* sender, std::vector<std::string> args)
{
	(void) args;
	return sender->sendRawMessage("PONG :ft_irc");
}
