/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QuitCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:58:05 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:29:58 by nours42          ###   ########.fr       */
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
