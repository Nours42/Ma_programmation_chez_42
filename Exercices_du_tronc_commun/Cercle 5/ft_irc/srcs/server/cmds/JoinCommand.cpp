/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JoinCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:53:05 by nours42           #+#    #+#             */
/*   Updated: 2023/11/02 15:42:58 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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