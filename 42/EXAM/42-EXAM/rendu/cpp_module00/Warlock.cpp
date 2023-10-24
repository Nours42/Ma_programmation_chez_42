/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:34:19 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/24 15:12:24 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::~Warlock( void )
{
	std::cout << this->getName() << ": My job here is done!" << std::endl;
}

Warlock::Warlock(std::string const &name, std::string const &title)
{
	this->_name = name;
	this->_title = title;
	std::cout << name << ": This looks like another boring day." <<std::endl;
}

//// setter ////

void	Warlock::setTitle(std::string const &newTitle)
{
	this->_title = newTitle;
}

//// getter ////

std::string	const &Warlock::getName(void) const
{
	return(this->_name);
}

std::string	const &Warlock::getTitle(void) const
{
	return(this->_title);
}

void	Warlock::introduce(void) const
{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
	
}
