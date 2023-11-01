/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JoinCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:53:05 by nours42           #+#    #+#             */
/*   Updated: 2023/11/01 14:53:37 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "cmds/JoinCommand.hpp"
#include "Console.hpp"

JoinCommand::JoinCommand(Server* server) : _server(server) {}
JoinCommand::~JoinCommand(void) {}

bool JoinCommand::onCommand(User* sender, std::vector<std::string> args)
{
	if (!sender->isConnected())
		return !sender->sendMessage(ERR_ALREADYREGISTRED, ":You have not registered");

	if (args.size() < 2)
		return !sender->sendMessage(ERR_NEEDMOREPARAMS, ":Not enough parameters");


	Channel* channel = _server->getChannels().get(args[1]);
	if (channel == NULL)
	{
		channel = _server->getChannels().add(args[1], "");
		channel->addOperator(sender);
		channel->setCreator(sender);
	}
	Channel* tmp = _server->getChannels().get(sender->getCurrentChannel());
	if (tmp != NULL) tmp->leave(sender);

	if (channel->isFull())
		return (!sender->sendMessage(ERR_CHANNELISFULL, ":Limited to a certain amount of users."));

	if (channel->isSetMode('i', ""))
		return (!sender->sendMessage(ERR_INVITEONLYCHAN, ":Is invite-only."));

	if (channel->isBanList(sender) && !channel->isInviteList(sender) && !channel->isExcepList(sender))
		return (!sender->sendMessage(ERR_BANNEDFROMCHAN, ":You can't join because you're banned."));

	if (!channel->isSetMode('p', "")
		|| channel->isOperator(sender)
		|| channel->isInviteList(sender)
		|| channel->isCreator(sender)
		|| (args.size() == 3 && channel->isPassword(args[2])))
		channel->join(sender);
	else return !sender->sendMessage(ERR_NEEDREGGEDNICK, ":Cannot join channel (+p)");

	if (channel->getTopic() == "")
		sender->sendMessage(RPL_NOTOPIC, args[1] + " :No topic is set");
	else
		sender->sendMessage(RPL_TOPIC, args[1] + " :" + channel->getTopic());
	sender->sendMessage(RPL_NAMREPLY, "= " + args[1] + " :" + channel->getUsersList());
	sender->sendMessage(RPL_ENDOFNAMES, args[1] + " :End of NAMES list");
	if (channel->isInviteList(sender) && sender->getCurrentChannel() == channel->getName())
		channel->deleteInviteList(sender);
	return true;
}