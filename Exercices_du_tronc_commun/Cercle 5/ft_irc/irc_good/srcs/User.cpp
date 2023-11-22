/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:20:50 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/22 13:20:53 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_irc.hpp"

User::User(int & fd)
{
	this->fd = fd;
	this->conStep = 1;
}

User::~User()
{
}

bool	User::operator==(User & user)
{
	if (this->fd == user.fd)
		return true;
	return false;
}

bool	User::operator!=(User & user)
{
	if (this->fd == user.fd)
		return false;
	return true;
}
