/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QuitCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:19:15 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:19:17 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "Console.hpp"
#include "cmds/QuitCommand.hpp"

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
