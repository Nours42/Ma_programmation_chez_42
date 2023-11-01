/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:54:04 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 14:54:15 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "cmds/ListCommand.hpp"
#include "Console.hpp"
#include "Message.hpp"
#include "Utils.hpp"

ListCommand::ListCommand(Server *server) : _server(server) {};
ListCommand::~ListCommand(void) {}

static void sendChannelInfo(User *sender, Channel *channel)
{
	std::stringstream ss;
	ss << ":" << channel->getName() << " :" << channel->getTopic();
	sender->sendMessage(RPL_LIST, ss.str());
}

static void sendChannelInfoFiltered(User *sender, Channel *channel, std::vector<std::string> names)
{
	for (size_t i = 0; i < names.size(); i++)
	{
		if (channel->getName() == names[i])
			return (void) sendChannelInfo(sender, channel);
	}
}

bool	ListCommand::onCommand(User *sender, std::vector<std::string> args)
{
	if (!sender->isConnected())
		return !sender->sendMessage(ERR_NOTREGISTERED, ":You have not registered");

	if (args.size() > 2)
		return !sender->sendMessage(ERR_NEEDMOREPARAMS, ":Too many parameters");

	std::vector<std::string> channelsName;
	if (args.size() == 2)
		channelsName = Utils::str_split(args[1], ",");

	std::map<std::string, Channel*> channels = _server->getChannels().getChannels();
	std::map<std::string, Channel*>::iterator begin = channels.begin();
	for (; channels.size() > 0 && begin != channels.end(); begin++)
	{
		if (begin->second->isSetMode('p', "") || begin->second->isSetMode('s', ""))
			continue ;

		if (channelsName.size() > 0)
			sendChannelInfoFiltered(sender, begin->second, channelsName);
		else sendChannelInfo(sender, begin->second);
	}
	sender->sendMessage(RPL_LISTEND, ":End of LIST");

	return true;
}