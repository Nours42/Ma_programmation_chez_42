/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelpCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:Exercices_du_tronc_commun/Cercle 5/ft_irc/srcs/server/cmds/HelpCommand.cpp
/*   Created: 2023/11/07 09:40:58 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/07 09:48:34 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//////////////////////////////// A QUOI JE SERS ///////////////////////////////
//
//  Je sers a reafficher les commandes et leurs options
//
//  J'ai donc les fonctions :
//
//		HELP -	rappelle les differents menu HELP suivants :
//		JOINHELP -	rappelle les fonctions dispos et options de JOIN
//		MODEHELP -	rappelle les fonctions dispos et options de MODE
//		QUITHELP -	rappelle les fonctions dispos et options de QUIT
//		TOPICHELP -	rappelle les fonctions dispos et options de TOPIC
//				
//
///////////////////////////////////////////////////////////////////////////////

=======
/*   Created: 2023/11/18 18:31:02 by nours42           #+#    #+#             */
/*   Updated: 2023/11/18 18:31:03 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds/KickCommand.hpp"

KickCommand::KickCommand(Server *server) : _server(server) {}
KickCommand::~KickCommand(void) {}

bool	KickCommand::onCommand(User *sender, std::vector<std::string> args)
{
	User	*target = NULL;
	Channel	*channel = NULL;

	if (!sender->isConnected())
		return !sender->sendMessage(ERR_NOTREGISTERED, ":You have not registered");

	if (args.size() < 3)
		return (!sender->sendMessage(ERR_NEEDMOREPARAMS, args[0] + " :Not enough parameters"));

	if (!(channel = _server->getChannels().get(args[1])))
		return (!sender->sendMessage(ERR_NOSUCHCHANNEL, args[1] + " :No such channel"));

	if (sender->getCurrentChannel() != channel->getName())
		return (!sender->sendMessage(ERR_NOTONCHANNEL, channel->getName() + " :You're not on that channel"));

	if (!channel->isOperator(sender))
		return (!sender->sendMessage(ERR_CHANOPRIVSNEEDED, channel->getName() + " :You're not channel operator"));

	if (!(target = _server->getUsers().findbyNickname(args[2])))
		return (!sender->sendMessage(ERR_NOSUCHNICK, args[2] + " :No such nick/channel"));

	if (target->getCurrentChannel() != channel->getName())
		return (!sender->sendMessage(ERR_USERNOTINCHANNEL, target->getNickname() + " " + channel->getName() + " :They aren't on that channel"));

	if (args.size() == 3)
		return (channel->kick(sender, target, ""));
	return (channel->kick(sender, target, args[3]));
}
>>>>>>> 80cc973 (ft_irc):Exercices_du_tronc_commun/Cercle 5/ft_irc/srcs/server/cmds/KickCommand.cpp
