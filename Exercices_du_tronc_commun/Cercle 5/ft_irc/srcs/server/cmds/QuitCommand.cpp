/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QuitCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:56:52 by nours42           #+#    #+#             */
/*   Updated: 2023/11/02 11:54:01 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../../includes/Console.hpp"
#include "../../../includes/cmds/QuitCommand.hpp"
#include "../../../includes/Message.hpp"

QuitCommand::QuitCommand(Server *server) : _server(server) {}
QuitCommand::~QuitCommand(void) {}

bool QuitCommand::onCommand(User* sender, std::vector<std::string> args)
{
	(void) args;

	if (!sender->isConnected())
		return !sender->sendMessage(ERR_NOTREGISTERED, ":You have not registered");

	if (!sender->getCurrentChannel().empty())
		_server->getChannels().leave(sender->getCurrentChannel(), sender);

	_server->getUsers().remove(sender->getSocket());

	Console::print("- USER", sender->to_string(false) + " has quit", Console::PURPLE);
	close(sender->getSocket());

	return true;
}
