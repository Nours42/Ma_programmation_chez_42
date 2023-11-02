/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:56:11 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 16:42:22 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../../includes/cmds/OperCommand.hpp"
#include "Console.hpp"
#include "Message.hpp"

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

OperCommand::OperCommand(Server *server) : _server(server) {};
OperCommand::~OperCommand(void) {}

bool	OperCommand::onCommand(User *sender, std::vector<std::string> args)
{
	if (!sender->isConnected())
		return !sender->sendMessage(ERR_NOTREGISTERED, ":You have not registered");

	if (args.size() != 3)
		return !sender->sendMessage(ERR_NEEDMOREPARAMS, ":Not enough parameters");

	if (args[2] == _server->getOpPassword())
	{
		sender->addMode('o');
		sender->sendMessage(RPL_YOUREOPER, ":You are now an IRC operator");
		return true;
	}
	sender->sendMessage(ERR_PASSWDMISMATCH, ":Password incorrect");
	return (true);
}
