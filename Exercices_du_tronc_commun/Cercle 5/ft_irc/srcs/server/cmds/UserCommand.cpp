/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:57:16 by nours42           #+#    #+#             */
/*   Updated: 2023/11/02 11:52:47 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cmds/UserCommand.hpp"
#include "../../../includes/Message.hpp"

UserCommand::UserCommand(Server *server) : _server(server)  {}
UserCommand::~UserCommand(void) {}

bool UserCommand::onCommand(User* sender, std::vector<std::string> args)
{
	if (sender->isConnected())
		return !sender->sendMessage(ERR_ALREADYREGISTRED, ":Unauthorized command (already registered)");

	if (args.size() < 5)
		return !sender->sendMessage(ERR_NEEDMOREPARAMS, ":Not enough parameters");

	if (sender->getUsername() == "")
	{
		sender->setUsername(args[1]);
		sender->setHostname(args[3]);
		sender->setRealname(args[4]);
	}

	return sender->tryConnect();
}
