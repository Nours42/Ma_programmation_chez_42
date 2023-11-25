/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PartCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:18:46 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/21 13:18:47 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "Console.hpp"
#include "cmds/PartCommand.hpp"

PartCommand::PartCommand(Server *server) : _server(server) {}
PartCommand::~PartCommand(void) {}

static bool leaveChannel(Server* server, std::string name, User* user)
{
	Channel* channel = server->getChannels().get(name);
	if (channel == NULL)
		return false;
	channel->leave(user);
	return true;
}

bool PartCommand::onCommand(User* sender, std::vector<std::string> args)
{
	if (!sender->isConnected())
		return !sender->sendMessage(ERR_NOTREGISTERED, ":You have not registered");

	if (args.size() < 2)
		return !sender->sendMessage(ERR_NEEDMOREPARAMS, ":Not enough parameters");

	leaveChannel(_server, args[1], sender);

	if (args.size() > 2)
	{
		for (size_t i = 2; i < args.size(); i++)
		{
			std::vector<std::string> channels = Utils::str_split(args[i], ",");
			for (size_t j = 0; j < channels.size(); j++)
				leaveChannel(_server, channels[j], sender);
		}
	}
	return true;
}