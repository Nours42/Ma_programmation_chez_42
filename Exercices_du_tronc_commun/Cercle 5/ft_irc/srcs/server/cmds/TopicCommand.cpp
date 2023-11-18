/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TopicCommand.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2023/10/30 15:29:43 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/07 10:27:23 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//////////////////////////////// A QUOI JE SERS ///////////////////////////////
//
//  OBLIGATOIRE DANS LE SUJET : TOPIC
//  Je sers a parametrer le Topic d'un channel (son nom).
//
//  J'ai donc les fonctions :
//		CHANGETOPIC -	recupere le channel, le user et verifie que celui-ci
//						peut changer le TOPIC
//
///////////////////////////////////////////////////////////////////////////////

//	bool	CanIChangeTopic(User* sender, Channel *channel)
// {
//		verifie si le channel existe
//			verifie si le sender existe
//			verfie qu'il est les droits
// 				si ok deux fois, rappelle le TOPIC avant modification et les
//					eventuelles regles de taille du TOPIC
//				repond OUI
// 		repond non dans les autres cas
// }

// void	ChangeTopic(User *sender, Channel *channel)
//{
//		lance CanIChangeTopic
//			si OK : prompt cin attends le nouveau TOPIC
//			regarde si le topic repond aux regles (longueur du TOPIC)
//			si ok, change le TOPIC.
//}
=======
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
>>>>>>> 80cc973 (ft_irc)
