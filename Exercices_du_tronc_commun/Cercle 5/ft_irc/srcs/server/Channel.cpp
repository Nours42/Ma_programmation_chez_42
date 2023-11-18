<<<<<<< HEAD
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









=======
#include "Channel.hpp"

//  Constructor & Destructor :
//  ----------------------------------------------------

Channel::Channel(std::string name, std::string topic) : _name(name), _topic(topic), _password(""), _limit(-1) {}
Channel::~Channel(void) {}

//  Join & Leave Channel :
//  ----------------------------------------------------

bool	Channel::join(User* user)
{
	user->setCurrentChannel(_name);
	_users.push_back(user);
	rawBroadcast(user->to_string(isSetMode('a', "")) + " JOIN " + getName(), user);
	user->sendRawMessage(user->to_string(isSetMode('a', "")) + " JOIN " + getName());
	return (true);
}

bool	Channel::leave(User* user)
{
	int index;
	if ((index = this->contains(user)) < 0)
		return false;
	user->sendRawMessage(user->to_string(isSetMode('a', "")) + " PART :" + getName());
	rawBroadcast(user->to_string(isSetMode('a', "")) + " PART :" + getName(), user);
	user->setCurrentChannel("");
	_users.erase(_users.begin() + index);
	return true;
}

bool	Channel::kick(User* sender, User *target, std::string arg)
{
	int index;
	if ((index = this->contains(target)) < 0)
		return false;
	if (arg.empty()) {
		target->sendRawMessage(sender->to_string(isSetMode('a', "")) + " KICK " + getName() + " " + target->getNickname());
		rawBroadcast(sender->to_string(isSetMode('a', "")) + " KICK " + getName() + " " + target->getNickname(), target);
	}
	else {
		target->sendRawMessage(sender->to_string(isSetMode('a', "")) + " KICK " + getName() + " " + target->getNickname() + " :" + arg);
		rawBroadcast(sender->to_string(isSetMode('a', "")) + " KICK " + getName() + " " + target->getNickname() + " :" + arg, target);
	}
	target->setCurrentChannel("");
	_users.erase(_users.begin() + index);
	return true;
}

//  Channel contains user :
//  ----------------------------------------------------

int		Channel::contains(User* user)
{
	size_t index = 0;
	while (index < _users.size())
	{
		if (user->getUsername() == _users[index]->getUsername())
			return index;
		index++;
	}
	return -1;
}

int		Channel::contains(std::string name)
{
	for (std::size_t idx = 0; idx < _users.size(); idx += 1) {
		if (_users[idx]->getUsername() == name)
			return (idx);
	}
	return (-1);
}

//  Get & Set member types :
//  ----------------------------------------------------

std::string			Channel::getName(void) const { return _name; }
std::vector<User*>	Channel::getUsers(void) const { return _users; }

User*				Channel::getUser(std::string name)
{
	for (std::size_t idx = 0; idx < _users.size(); idx += 1) {
		if (_users[idx]->getUsername() == name)
			return (_users[idx]);
	}
	return (NULL);
}

void				Channel::setTopic(std::string new_topic) { this->_topic = new_topic; }
std::string			Channel::getTopic(void) const { return _topic; }


//  Broadcast :
//  ----------------------------------------------------

void	Channel::rawBroadcast(std::string message, User* sender)
{
	size_t i = 0;
	while (i < _users.size())
	{
		if (_users[i]->getUsername() != sender->getUsername()
			&& _users[i]->getCurrentChannel() == _name)
			_users[i]->sendRawMessage(message);
		i++;
	}
}

void	Channel::broadcast(std::string code, std::string message, User* sender)
{
	size_t i = 0;
	while (i < _users.size())
	{
		if (_users[i]->getUsername() != sender->getUsername()
			&& _users[i]->getCurrentChannel() == _name)
			_users[i]->sendMessage(code, message);
		i++;
	}
}

//  Creator :
//  ----------------------------------------------------

void				Channel::setCreator(User *user) { _creator = user ;}
User				*Channel::getCreator(void) const { return (_creator); }

bool				Channel::isCreator(User *user) const {
	if (user == _creator)
		return (true);
	return (false);
}

//  Operators :
//  ----------------------------------------------------

std::vector<User*>	Channel::getOperators(void) const { return (_operators); }

bool	Channel::isOperator(User *user) const
{
	for (std::size_t idx = 0; idx < _operators.size(); idx += 1) {
		if (_operators[idx] == user)
			return (true);
	}
	return (false);
}

void	Channel::addOperator(User *user)
{
	if (!isOperator(user))
		_operators.push_back(user);
}

void	Channel::deleteOperator(User *user)
{
	if (!isOperator(user))
		return ;
	_operators.erase(std::remove(_operators.begin(), _operators.end(), user), _operators.end());
}

//  Mode :
//  ----------------------------------------------------

std::multimap<char, std::string>	Channel::getModes(void) const { return (_modes); }

bool	Channel::isMode(char mode) const
{
	std::string		validModes = "OovaimnqpsrtklbeI";

	for (std::size_t idx = 0; idx < validModes.size(); idx += 1) {
		if (mode == validModes[idx])
			return (true);
	}
	return (false);
}

bool 	Channel::isSetMode(char mode, std::string params) const
{
	for (std::multimap<char, std::string>::const_iterator it = _modes.begin(); it != _modes.end(); it++) {
		if (it->first == mode && it->second == params)
			return (true);
	}
	return (false);
}

void	Channel::addMode(char mode, std::string params)
{
	for (std::multimap<char, std::string >::const_iterator it = _modes.begin(); it != _modes.end(); it++) {
		if (it->first == mode && it->second == params) {
			_modes.erase(_modes.find(it->first));
			break ;
		}
	}
	_modes.insert(std::pair<char, std::string>(mode, params));
}

void	Channel::deleteMode(char mode, std::string params)
{
	for (std::multimap<char, std::string >::const_iterator it = _modes.begin(); it != _modes.end(); it++)
	{
		if (it->first == mode && it->second == params)
			return ((void)_modes.erase(_modes.find(it->first)));
	}
}

bool	Channel::setMode(std::string mode, std::string params)
{
	if ((mode[0] != '+' && mode[0] != '-') || !isMode(mode[1]))
		return (false);
	if (mode[0] == '+')
		addMode(mode[1], params);
	else if (mode[0] == '-')
		deleteMode(mode[1], params);
	return (true);
}


//  Moderate :
//  ----------------------------------------------------

std::vector<User*>	Channel::getModerates(void) const { return (_operators); }

bool	Channel::isModerate(User *user) const
{
	for (std::size_t idx = 0; idx < _moderates.size(); idx += 1) {
		if (_moderates[idx] == user)
			return (true);
	}
	return (false);
}

void	Channel::addModerate(User *user)
{
	if (!isModerate(user))
		_moderates.push_back(user);
}

void	Channel::deleteModerate(User *user)
{
	if (!isModerate(user))
		return ;
	for (std::vector<User*>::const_iterator it = _moderates.begin(); it != _moderates.end(); it++) {
		if (*it == user)
			return ((void)_moderates.erase(_moderates.begin() + (it - _moderates.begin())));
	}
}

//  Password :
//  ----------------------------------------------------

void 				Channel::setPassword(std::string pass) { _password = pass ;}
void				Channel::unsetPassword(void) { _password = ""; }
std::string			Channel::getPassword(void) const { return (_password); }

bool				Channel::isPassword(std::string pass) const {
	if (!_password.empty() && pass == _password)
		return (true);
	return (false);
}

//  Limit :
//  ----------------------------------------------------

void				Channel::setLimit(std::string limit) { _limit = Utils::stoi(limit); }
void				Channel::unsetLimit(void) { _limit = -1; }
std::size_t			Channel::getLimit(void) const { return (_limit); }

bool				Channel::isFull(void) const {
	if (_users.size() >= _limit)
		return (true);
	return (false);
}

bool		Channel::checkLimit(std::string limit) {
	for (std::size_t idx = 0; idx < limit.size(); idx += 1) {
		if (isdigit(limit.at(idx)) == false)
			return (false);
	}
	return (true);
}

//  Banned Mask :
//  ----------------------------------------------------

std::vector<User*>	Channel::getBanList(void) const { return (_banList); }

bool	Channel::isBanList(User *user) const
{
	for (std::size_t idx = 0; idx < _banList.size(); idx += 1) {
		if (_banList[idx] == user)
			return (true);
	}
	return (false);
}

void	Channel::addBanList(User *user)
{
	if (!isBanList(user))
		_banList.push_back(user);
}

void	Channel::deleteBanList(User *user)
{
	if (!isBanList(user))
		return ;
	for (std::vector<User*>::const_iterator it = _banList.begin(); it != _banList.end(); it++) {
		if (*it == user)
			return ((void)_banList.erase(_banList.begin() + (it - _banList.begin())));
	}
}

//  Banned Exception Mask :
//  ----------------------------------------------------

std::vector<User*>	Channel::getExcepList(void) const { return (_excepList); }

bool	Channel::isExcepList(User *user) const
{
	for (std::size_t idx = 0; idx < _excepList.size(); idx += 1) {
		if (_excepList[idx] == user)
			return (true);
	}
	return (false);
}

void	Channel::addExcepList(User *user)
{
	if (!isExcepList(user))
		_excepList.push_back(user);
}

void	Channel::deleteExcepList(User *user)
{
	if (!isExcepList(user))
		return ;
	for (std::vector<User*>::const_iterator it = _excepList.begin(); it != _excepList.end(); it++) {
		if (*it == user)
			return ((void)_excepList.erase(_excepList.begin() + (it - _excepList.begin())));
	}
}

//  Invite only Mask :
//  ----------------------------------------------------

std::vector<User*>	Channel::getInviteList(void) const { return (_inviteList); }

bool	Channel::isInviteList(User *user) const
{
	for (std::size_t idx = 0; idx < _inviteList.size(); idx += 1) {
		if (_inviteList[idx] == user)
			return (true);
	}
	return (false);
}

void	Channel::addInviteList(User *user)
{
	if (!isInviteList(user))
		_inviteList.push_back(user);
}

void	Channel::deleteInviteList(User *user)
{
	if (!isInviteList(user))
		return ;
	for (std::vector<User*>::const_iterator it = _inviteList.begin(); it != _inviteList.end(); it++) {
		if (*it == user)
			return ((void)_inviteList.erase(_inviteList.begin() + (it - _inviteList.begin())));
	}
}

//  Everything else :
//  ----------------------------------------------------

std::string	Channel::getUsersList(void)
{
	std::stringstream ss;
	std::vector<User*>::iterator begin = _users.begin();
	std::vector<User*>::iterator end = _users.end();
	for (; begin != end; begin++)
	{
		User* user = (*begin);
		if (user == NULL) continue;
		if (isOperator(user)) ss << "@";
		ss << user->getNickname() << " ";
	}
	return ss.str();
}
>>>>>>> 80cc973 (ft_irc)


