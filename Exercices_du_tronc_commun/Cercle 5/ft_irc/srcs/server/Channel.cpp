/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:14:29 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/07 11:29:49 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Channel::Channel(std::string name, std::string topic) : _name(name), _topic(topic), _password(""), _limit(-1) {}
//Channel::~Channel(void) {}

///// ACTIONS ///

//bool	Channel::join(User* user)
//{
//}

//bool	Channel::leave(User* user)
//{
//}

//bool	Channel::kick(User* sender, User *target, std::string arg)
//{
//}

//void	Channel::getMessages(std::string message, User* sender)
//{
//		recupere les messages du channel toutes les x secondes.
//}

//void	Channel::post(std::string code, std::string message, User* sender)
//{
//		verifie si le premier mot est une commande
//		si oui tente d'executer la commande
//			si ok la commande s'execute rien a faire.
//			si non, message "Commande impossible - Taper HELP pour la liste"
//		si non
//			ajoute le message taper aux messages du channel.
//}

///// GETTERS ///
	///// LISTS ///

	//std::map<Channel*, std::string>		Channel::getChannel()
	//{
	//		retourne la liste des channels et leurs noms.
	//}

	//bool		Channel::isChannel(Channel *channel)
	//{
	//		retourne oui si le pointeur existe dans la liste std::map de getChannel
	//}

	//bool		Channel::isChannel(std::string name)
	//{
	//		retourne oui si le name existe dans la liste std::map de getChannel
	//}

	//std::vector<User*>		Channel::contains(std::string searchType)
	//{
	//		searchType : USER
	//			liste les users par leurs pointeurs.
	//		searchType : NAU
	//			liste les Non Actives Users par leurs pointeurs. les users NAU sont 
	//			ceux autorises a join mais pas present actuellement.
	//		searchType : MODO
	//			liste les users avec droit MODO par leurs pointeurs.
	//		searchType : BAN
	//			liste les users BAN du channel par leurs pointeurs.
	//
	//}

	//std::vector<std::string>		Channel::contains(std::string searchType)
	//{
	//		searchType : USERNAME
	//			liste les users par leurs nicknames.
	//		searchType : NAUNAME
	//			liste les Non Actives Users par leurs nicknames. les users NAU sont 
	//			ceux autorises a join mais pas present actuellement.
	//		searchType : MODONAME
	//			liste les users avec droit MODO par leurs nicknames.
	//		searchType : BANNAME
	//			liste les users BAN du channel par leurs nicknames.
	//}

	///// ONES ///

	//int		Channel::contains(User* user)
	//{
	//		recherche un user par son pointeur dans le channel.
	//			repond 0 si present
	//			repond 1 si absent
	//			repond 2 si NAU
	//			repond 3 si BAN
	//			repond 4 si MODO
	//}

	//int		Channel::contains(std::string name)
	//{
	//		recherche un user par son nickname dans le channel.
	//			repond 0 si present
	//			repond 1 si absent
	//			repond 2 si NAU
	//			repond 3 si BAN
	//			repond 4 si MODO
	//}

/// BAN ///

//void	Channel::addBan(User *sender, User *cible)
//{
//		verifie si channel existe
//			si non, message channel n'existe pas
//		verifie si sender existe et s'il a les droits
//			si non, message sender n'existe pas
//			si non, message n'a pas les droits
//		verifie si cible existe et fait partie de User ou NAU du channel (Channel::contains(User* cible) retourne tout sauf 1)
//			si non la cible ne fait pas partie des Users.
//			si non la cible ne fait pas partie des NAU.
//		verifie si Cible n'est pas deja BAN (Channel::contains(User* cible) retourne 3)
//			si non "la cible fait deja partie des users BAN"
//		BAN de la cible
//}


//void	Channel::deleteBan(User *sender, User *cible)
//{
//		verifie si channel existe
//			si non, message channel n'existe pas
//		verifie si sender existe et s'il a les droits
//			si non, message sender n'existe pas
//			si non, message n'a pas les droits
//		verifie si cible existe et fait partie des BAN du channel (Channel::contains(User* cible) retourne 3)
//			si non "la cible fait deja partie des users BAN"
//		UNBAN de la cible.
//}

/// PRINT ///

//std::string	Channel::printList(void)
//{
//	std::stringstream ss;
//	std::vector<User*>::iterator begin = _users.begin();
//	std::vector<User*>::iterator end = _users.end();
//	for (; begin != end; begin++)
//	{
//		User* user = (*begin);
//		if (user == NULL) continue;
//		if (isOperator(user)) ss << "@";
//		ss << user->getNickname() << " ";
//	}
//	return ss.str();
//}

//void	Channel::addModo(bool newChannel, User *user)
//{
//		utilisation uniquement a la creation d'un channel, le user est automatiquement modo de celui-ci.
//		s'il leave, quit ou reduit ses droits sans autre user dessus = detruire le channel.
//}

//void	Channel::addModo(Channel *channel, User *sender, User *cible)
//{
//		verifie si channel existe
//			si non, message channel n'existe pas
//		verifie si sender existe et s'il a les droits
//			si non, message sender n'existe pas
//			si non, message n'a pas les droits
//		verifie si cible existe et fait partie des MODO du channel (Channel::contains(User* cible) retourne 4)
//			si non "la cible fait deja partie des users MODO"
//		ajoute MODO a la cible.
//}

//void	Channel::deleteModo(User *sender, User *cible)
//{
//		verifie si channel existe
//			si non, message channel n'existe pas
//		verifie si sender existe et s'il a les droits
//			si non, message sender n'existe pas
//			si non, message n'a pas les droits
//		verifie si cible existe et fait partie des MODO du channel (Channel::contains(User* cible) retourne 4)
//			si non, renvoie "X n'est pas MODO"
//			si oui, verifie que sender != cible
//				si ce n'est pas le cas, enleve MODO a la cible.
//				si c'est le cas
//					verifie la taille du vector retournee par Channel::contains("MODO")
//					si taille = 1 : previens du delete du channel et le supprime.
//					si taille > 1 : enleve le MODO de la cible.
//}

///// MODES ///

//bool 	Channel::isSetMode(char mode, std::string params) const
//{
//	for (std::multimap<char, std::string>::const_iterator it = _modes.begin(); it != _modes.end(); it++) {
//		if (it->first == mode && it->second == params)
//			return (true);
//	}
//	return (false);
//}

//void	Channel::setMode(std::string mode, std::string params)
//{
//	if (mode[1] == 'o' || mode[1] == 's' || mode[1] == 'i')
//		if (mode[0] == '+')
//			addMode(mode[1], params);
//		else (mode[0] == '-')
//			deleteMode(mode[1], params);
//}

//void	Channel::addMode(char mode, std::string params)
//{
//	std::multimap<char, std::string >::iterator it = _modes.begin();
//	while (it != _modes.end())
//	{
//		if (it->first == mode && it->second == params)
//		{
//			_modes.erase(it);
//			break ;
//		}
//		it++;
//	}
//	_modes.insert(std::pair<char, std::string>(mode, params));
//}

//void	Channel::deleteMode(char mode, std::string params)
//{
//	for (std::multimap<char, std::string >::iterator it = _modes.begin(); it != _modes.end(); it++)
//	{
//		if (it->first == mode && it->second == params)
//			return ((void)_modes.erase(it));
//	}
//}

///// PASSWORDS ///

//bool	Channel::isPassword(std::string pass) const
//{
//	if (!_password.empty() && pass == _password)
//		return (true);
//	return (false);
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////











