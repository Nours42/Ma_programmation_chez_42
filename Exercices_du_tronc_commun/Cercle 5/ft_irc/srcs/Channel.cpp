/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:14:29 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/31 12:29:24 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Channel.hpp"

Channel::Channel(std::string name, std::string topic) : _name(name), _topic(topic), _password(""), _limit(-1) {}
Channel::~Channel(void) {}

/// ACTIONS ///

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


/// GETTERS ///

/// LISTS ///

	/// BAN ///

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
			return ((void)_banList.erase(it));
	}
}

bool	Channel::isBanList(User *user) const
{
	std::size_t idx = 0;

	while (idx < _banList.size())
	{
		if (_banList[idx] == user)
			return (true);
		idx++;
	}
	return (false);
}

	/// ExcepList ///

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
			return ((void)_excepList.erase(it));
	}
}

bool	Channel::isExcepList(User *user) const
{
	for (std::size_t idx = 0; idx < _excepList.size(); idx += 1) {
		if (_excepList[idx] == user)
			return (true);
	}
	return (false);
}

	/// InviteList ///
	
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
			return ((void)_inviteList.erase(it));
	}
}

bool	Channel::isInviteList(User *user) const
{
	std::size_t idx = 0;

	while (idx < _inviteList.size())
	{
		if (_inviteList[idx] == user)
			return (true);
		idx++;
	}
	return (false);
}

	/// ModerateList ///

bool	Channel::isModerate(User *user) const
{
	std::size_t idx = 0;

	while (idx < _moderates.size())
	{
		if (_moderates[idx] == user)
			return (true);
		idx++;
	}
	return (false);
}

/// USERS ///
User*	Channel::getUser(std::string name)
{
	std::size_t idx = 0;

	while (idx < _users.size())
	{
		if (_users[idx]->getUsername() == name)
			return (_users[idx]);
		idx++;
	}
	return (NULL);
}

/// CREATORS ///

void	Channel::setCreator(User *user) { _creator = user ;}

bool	Channel::isCreator(User *user) const
{
	if (user == _creator)
		return (true);
	return (false);
}


/// OPERATORS ///
void	Channel::addOperator(User *user)
{
	if (!isOperator(user))
		_operators.push_back(user);
}

bool	Channel::isOperator(User *user) const
{
	std::size_t idx = 0;
	while (idx < _operators.size())
	{
		if (_operators[idx] == user)
			return (true);
		idx++;
	}
	return (false);
}

void	Channel::deleteOperator(User *user)
{
	std::vector<User*>::const_iterator it = _operators.begin();

	if (!isOperator(user))
		return ;
	while (it != _operators.end())
	{
		if (*it == user)
			return ((void)_operators.erase(it));
		it++;
	}
}

/// LIMITS ///

void	setLimit(std::string limit)
{
	std::istringstream ss(limit);
	if (!(ss >> _limit))
		Console::error("Erreur : La chaîne n'est pas un nombre valide.");
}

bool	Channel::isFull(void) const
{
	if (_users.size() >= _limit)
		return (true);
	return (false);
}

bool	Channel::checkLimit(std::string limit)
{
	std::size_t idx = 0;

	while (idx < limit.size())
	{
		if (isdigit(limit.at(idx)) == false)
			return (false);
		idx++;
	}
	return (true);
}

/// MODERATES ///
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
			return ((void)_moderates.erase(it));
	}
}

/// MODES ///

void	Channel::deleteMode(char mode, std::string params)
{
	for (std::multimap<char, std::string >::const_iterator it = _modes.begin(); it != _modes.end(); it++)
	{
		if (it->first == mode && it->second == params)
			return ((void)_modes.erase(it));
	}
}

bool 	Channel::isSetMode(char mode, std::string params) const
{
	for (std::multimap<char, std::string>::const_iterator it = _modes.begin(); it != _modes.end(); it++) {
		if (it->first == mode && it->second == params)
			return (true);
	}
	return (false);
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

/// PASSWORDS ///

bool	Channel::isPassword(std::string pass) const
{
	if (!_password.empty() && pass == _password)
		return (true);
	return (false);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////











