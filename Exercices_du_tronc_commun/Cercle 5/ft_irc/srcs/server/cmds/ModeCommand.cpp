/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModeCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:27:45 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/02 15:41:51 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//////////////////////////////// A QUOI JE SERS ///////////////////////////////
//
//  OBLIGATOIRE DANS LE SUJET
//  Je sers a parametrer le mode d'un channel. Les modes existants sont :
//		o - give/take channel operator privileges;
//		s - secret channel flag;
//		i - invite-only channel flag;
//
//  J'ai donc les fonctions :
//      SENDCHANNELMODE -	recupere le mode d'un channel et l'affiche, cela
// 							peut servir a savoir pourQuoi un user n'a pas acces
// 							a un serveur. ATTENTION si un user n'est pas
//							operator, cela ne doit afficher les channel secret.
//		GIVEMODERATOR - TAKEMODERATOR - donne les droits operator a un user.
//		SECRETMODE	-		Change le mode en secret
//		INVITEMODE	-		Change le mode en invite-only mode
//
///////////////////////////////////////////////////////////////////////////////

// #include "../../../includes/cmds/ModeCommand.hpp"
// #include "../../../includes/Channel.hpp"
// #include "../../../includes/Message.hpp"

// bool ModeCommand::onCommand(User* sender, std::vector<std::string> args)
// {
// 	
// }