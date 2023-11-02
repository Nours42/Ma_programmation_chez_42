/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NamesCommand.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:55:26 by nours42           #+#    #+#             */
/*   Updated: 2023/11/02 10:00:28 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cmds/NamesCommand.hpp"
#include "../../../includes/Server.hpp"
#include "../../../includes/Utils.hpp"
#include "../../../includes/Message.hpp"

NamesCommand::NamesCommand(Server *server) : _server(server) {}
NamesCommand::~NamesCommand(void) {}

static bool sendChannelNames(User *sender, Channel *channel)
{
	if (channel == NULL)
		return false;
	if (channel->isSetMode('p', "") || channel->isSetMode('s', ""))
		return (true);
	std::stringstream ss;
	ss << "= " << channel->getName() << " :";
	ss << channel->getUsersList();
	sender->sendMessage(RPL_NAMREPLY, ss.str());
	sender->sendMessage(RPL_ENDOFNAMES, channel->getName() + " :End of NAMES list.");
	return true;
}

bool NamesCommand::onCommand(User* sender, std::vector<std::string> args)
{
	if (!sender->isConnected())
		return !sender->sendMessage(ERR_NOTREGISTERED, ":You have not registered");

	if (args.size() > 2)
		return !sender->sendMessage(ERR_NEEDMOREPARAMS, ":Too many parameters");

	if (args.size() == 2)
	{
		std::vector<std::string> channels = Utils::str_split(args[1], ",");
		if (channels.size() == 1)
			return sendChannelNames(sender, _server->getChannels().get(channels[0]));
		for (size_t i = 0; i < channels.size(); i++)
		{
			Channel *channel = _server->getChannels().get(channels[i]);
			if (channel != NULL) sendChannelNames(sender, channel);
		}
		return true;
	}

	std::map<std::string, Channel*> channels = _server->getChannels().getChannels();
	for (std::map<std::string, Channel*>::iterator it = channels.begin(); it != channels.end(); ++it)
		sendChannelNames(sender, it->second);

	return true;
}