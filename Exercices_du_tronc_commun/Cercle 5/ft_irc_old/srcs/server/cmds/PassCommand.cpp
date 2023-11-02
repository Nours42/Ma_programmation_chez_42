/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:56:24 by nours42           #+#    #+#             */
/*   Updated: 2023/11/02 11:52:30 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cmds/PassCommand.hpp"
#include "../../../includes/Server.hpp"
#include "../../../includes/Utils.hpp"
#include "../../../includes/Message.hpp"

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
