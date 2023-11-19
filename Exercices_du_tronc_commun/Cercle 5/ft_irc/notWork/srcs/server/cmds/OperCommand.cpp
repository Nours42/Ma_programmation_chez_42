/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:01:30 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:30:05 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "cmds/OperCommand.hpp"
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
