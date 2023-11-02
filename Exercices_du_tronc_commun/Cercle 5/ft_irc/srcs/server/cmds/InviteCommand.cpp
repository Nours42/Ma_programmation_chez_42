/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InviteCommand.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:27:29 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/02 15:42:19 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//////////////////////////////// A QUOI JE SERS ///////////////////////////////
//
//  OBLIGATOIRE DANS LE SUJET
//  Je sers a inviter un user dans un salon invite-only (le mode +i)
//
//  J'ai donc les fonctions :
//      INVITE -    prend en params un userName et un channelName, doit verifier
//                  que l'user est operator sur le channel +i (avoir le droit
//                  d'inviter au pire).
//
///////////////////////////////////////////////////////////////////////////////

#include "../../../includes/cmds/InviteCommand.hpp"
// #include "../../../includes/Channel.hpp"
// #include "../../../includes/Message.hpp"

// bool	InviteCommand::onCommand(User* sender, std::vector<std::string> args)
// {
// }