/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModeCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:27:45 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/07 09:48:15 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//////////////////////////////// A QUOI JE SERS ///////////////////////////////
//
//  OBLIGATOIRE DANS LE SUJET : MODE
//      Je sers a parametrer le mode d'un channel. Les modes existants sont :
//          o - give/take channel operator privileges;
//          s - secret channel flag;
//          i - invite-only channel flag;
//
//  J'ai donc les fonctions :
//
//      SENDCHANNELMODE -	recupere le mode d'un channel et l'affiche, cela
// 							peut servir a savoir pourQuoi un user n'a pas acces
// 							a un serveur. ATTENTION si un user n'est pas
//							operator, cela ne doit afficher les channel secret.
//		GIVEMODERATOR - TAKEMODERATOR - donne les droits operator a un user.
//		SECRETMODE	-		Change le mode en secret
//		INVITEMODE	-		Change le mode en invite-only mode
//
///////////////////////////////////////////////////////////////////////////////

