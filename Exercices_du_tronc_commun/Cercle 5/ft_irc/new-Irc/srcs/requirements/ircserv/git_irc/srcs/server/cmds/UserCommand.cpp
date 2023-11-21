/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:57:59 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:29:54 by nours42          ###   ########.fr       */
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