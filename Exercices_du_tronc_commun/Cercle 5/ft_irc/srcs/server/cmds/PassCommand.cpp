/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:56:24 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 14:56:25 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds/PassCommand.hpp"
#include "Server.hpp"
#include "Utils.hpp"

PassCommand::PassCommand(Server *server) : _server(server) {}
PassCommand::~PassCommand(void) {}

bool PassCommand::onCommand(User* sender, std::vector<std::string> args)
{
	if (sender->isConnected())
		return !sender->sendMessage(ERR_ALREADYREGISTRED, ":Unauthorized command (already registered)");

	if (args.size() != 2)
		return !sender->sendMessage(ERR_NEEDMOREPARAMS, ":Not enough parameters");

	if (args[1] == _server->getPassword()) sender->setAccepted(true);
	else return !sender->sendMessage(ERR_PASSWDMISMATCH, ":Password incorrect");

	return sender->tryConnect();
}
