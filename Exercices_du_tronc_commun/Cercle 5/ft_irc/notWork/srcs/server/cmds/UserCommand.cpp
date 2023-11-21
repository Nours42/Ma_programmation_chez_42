/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:19:21 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:19:22 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds/UserCommand.hpp"

UserCommand::UserCommand(void) {}
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
