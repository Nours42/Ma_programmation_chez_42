/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TopicCommand.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:13:00 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:29:55 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "cmds/TopicCommand.hpp"
#include "Console.hpp"

TopicCommand::TopicCommand(Server *server) : _server(server) {}
TopicCommand::~TopicCommand(void) {}


bool	TopicCommand::onCommand(User *sender, std::vector<std::string> args) {
	Channel	*channel = NULL;

	if (!sender->isConnected())
		return !sender->sendMessage(ERR_NOTREGISTERED, ":You have not registered");

	if (args.size() < 2)
		return (!sender->sendMessage(ERR_NEEDMOREPARAMS, args[0] + " :Not enough parameters"));

	if (!(channel = _server->getChannels().get(args[1])))
		return (false);

	if (channel->isSetMode('p', "") || channel->isSetMode('s', ""))
		return (!sender->sendMessage(ERR_NOSUCHCHANNEL, channel->getName() + " :No such channel"));

	if (sender->getCurrentChannel() != args[1])
		return (!sender->sendMessage(ERR_NOTONCHANNEL, args[1] + " :You're not on that channel"));

	if (args.size() == 3)
	{
		if (!channel->isOperator(sender))
			return (!sender->sendMessage(ERR_CHANOPRIVSNEEDED, args[1] + " :You're not channel operator"));
		(args[2].compare(":") == 0) ? channel->setTopic("") : channel->setTopic(args[2]);
	}
	if (args.size() >= 2)
		(channel->getTopic() == "") ? sender->sendMessage(RPL_NOTOPIC, args[1] + " :No topic is set") :
			sender->sendMessage(RPL_TOPIC, args[1] + " :" + channel->getTopic());
	return (true);
}
