/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JoinCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:08:48 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:30:35 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

<<<<<<< HEAD
//////////////////////////////// A QUOI JE SERS ///////////////////////////////
//
//  Je sers a un user pour rejoindre un salon public
//
//  J'ai donc les fonctions :
//
//		CONNECT -	prend en params un channelName et recupere le user, doit
// 					verifier que le channel est invite only et que cet user est
//					autorise a y acceder
// 
// OBLIGATOIRE DANS LE SUJET :
//  Je sers a inviter un user dans un salon invite-only (le mode +i)
//
//  J'ai donc les fonctions :
//      INVITE -    prend en params un userName et un channelName, use CanIJoin de JoinCOmmand
//				
//
///////////////////////////////////////////////////////////////////////////////

//	bool	CanIJoin(User* sender, Channel *channel)
// {
//		verifie si le channel existe et si private
//			verifie si le sender existe
// 				si channel general, repond oui
// 				si channel private, verifie que le sender a le droit d'y acceder
//					repond oui
// 		repond non dans les autres cas
// }

// void		Connect(User* sender, Channel *channel)
// {
//		if (CanIJoin)
//			AddUser to UserList du Channel
//		else
//			Message "you can't"
// }

// void     Invite(User* sender, User* cible, Channel* channel)
// {
//      verifie si le channel existe et si private
//  		si channel general, repond "le channel est en mode general, pas besoin d'invite"
//		verifie si le sender existe
//			verifie s'il a les droits d'invite
//				verifie si la cible existe
//				verifie si la cible n'est pas deja sur le channel
//					si deja sur le channel, le dit "User cible deja sur le channel x"
// 				si la cible n'y est pas ajoute la cible dans les user du channel x
// 				+ previent le sender de "Cible ajoute a X"
//				+ previent la cible "vous faites desormais partie du channel X, 
//							vous pouvez le rejoindre en faisant JOIN X"
// 		repond non dans les autres cas
// }
=======
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
	// leave current channel
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
	// TODO: #41 set @ before users' name when they are operators
	sender->sendMessage(RPL_NAMREPLY, "= " + args[1] + " :" + channel->getUsersList());
	sender->sendMessage(RPL_ENDOFNAMES, args[1] + " :End of NAMES list");
	if (channel->isInviteList(sender) && sender->getCurrentChannel() == channel->getName())
		channel->deleteInviteList(sender);
	return true;
}
>>>>>>> 80cc973 (ft_irc)
