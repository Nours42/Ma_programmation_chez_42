/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
/*   KickCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:26:09 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/02 15:45:23 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//////////////////////////////// A QUOI JE SERS ///////////////////////////////
//
//  OBLIGATOIRE DANS LE SUJET : KICK
//  Je sers a virer un user d'un salon
//
//  J'ai donc les fonctions :
//      KICK -      prend en params un userName (le sender), et un groupe d'argument (std::vertor<std::string) contenant le channel cible, l'user cible
//      CANIKICK -  doit verifier que l'user est operator sur le channel.
//		LEAVE -		permet a un User de quitter un channel.
//
///////////////////////////////////////////////////////////////////////////////

// bool	CanIKick(User *sender, std::vector<std::string> args)
// {
// 	    std::vector<std::string> args contient le channel et l'user cible
//		verifie aue le sender existe
//			verifie que le channel existe
//				verfie que le sender a les droits creator sur le channel cible
//					verfifie que l'user existe
//						verifie que l'user cible est sur le channel cible
//							repond oui
//						repond que l'user cible n'est pas user du channel cible
//					repond que l'user cible n'existe pas
//				repond que le sender n'a pas les droits sur le channel
//			repond que le channel n'existe pas
//		repond "who are you motherfucker ?"
// }

// void	Kick(User *cible, Channel *ChannelCible)
// {
//	 lance un CanIKick
// 		si oui, vire la cible du channelCible
// 		si non, ne fait rien
// }

// void	Leave(User *sender, Channel *channel)
// {
//		verifie que le sender existe
//		verifie que le channel existe
//		verifie que le sender fait partie des utilisateurs actifs du channel
//			si trois fois ok, enleve le sender des utilisateurs actifs.
// }
=======
/*   QuitCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:58:05 by nours42          #+#    #+#             */
/*   Updated: 2023/11/18 18:29:58 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "Console.hpp"
#include "cmds/QuitCommand.hpp"

QuitCommand::QuitCommand(Server *server) : _server(server) {}
QuitCommand::~QuitCommand(void) {}

bool QuitCommand::onCommand(User* sender, std::vector<std::string> args)
{
	(void) args;

	if (!sender->isConnected())
		return !sender->sendMessage(ERR_NOTREGISTERED, ":You have not registered");

	if (!sender->getCurrentChannel().empty())
		_server->getChannels().leave(sender->getCurrentChannel(), sender);

	_server->getUsers().remove(sender->getSocket());

	Console::print("- USER", sender->to_string(false) + " has quit", Console::PURPLE);
	close(sender->getSocket());

	return true;
}
>>>>>>> 80cc973 (ft_irc)
