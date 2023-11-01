/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:07:40 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/01 16:55:28 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/User.hpp"

bool	User::tryConnect(void)
{
	if (isConnected() || !isAccepted() || getUsername().empty() || getNickname().empty())
		return (false);
	setConnected(true);
	std::cout << "Welcome to my IRC " << _username << " !" << std::endl;
	std::cout << _username << " has join IRC" << std::endl;
	return (true);
};

bool	User::sendRawMessage(std::string message)
{
	Console::print("<= SENT", message.c_str(), Console::GREEN);
	message += "\r\n";
	return send(this->getSocket(), message.c_str(), message.length(), 0) != -1;
};

bool	User::sendMessage(std::string code, std::string message)
{
	std::stringstream ss;
	ss	<< ":ft_irc " << code << " " << this->getNickname() << " " << message;
	return this->sendRawMessage(ss.str());
};

bool	User::useMode(std::string mode)
{
	if (mode.size() != 2)
		return false;
	if (mode[0] != '+' && mode[0] != '-')
		return false;
	if (mode[1] != 'a' && mode[1] != 'i' && mode[1] != 'w' && mode[1] != 'r'
		&& mode[1] != 'o' && mode[1] != 'O' && mode[1] != 's')
		return false;
	if (mode[0] == '+' && mode[1] != 'o' && mode[1] != 'O' && mode[1] != 'a')
		addMode(mode[1]);
	if (mode[0] == '-' && mode[1] != 'a')
		removeMode(mode[1]);
	return true;
}

std::string	User::to_string(bool isAnon)
{
	if (isAnon)
		return ":anonymous!anonymous@anonymous";
	return (":" + _nickname + "!" + _username + "@" + this->getAddress());
}

bool	User::isMode(char mode)
{
	if (!hasMode(mode))
		return false;
	return _modes[mode];
}