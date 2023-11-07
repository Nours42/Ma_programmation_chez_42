/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TopicCommand.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:29:43 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/07 09:52:38 by sdestann         ###   ########.fr       */
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
//			si OK : 
//}