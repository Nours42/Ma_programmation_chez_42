/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:35:13 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/02 18:32:38 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock()
{}

Warlock::Warlock(Warlock const &ref)
{
	*this = ref;
}

Warlock &Warlock::operator=(Warlock const &ref)
{
	this->_name = ref._name;
	this->_title = ref._title;
	return (*this);
}

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

std::string const	&Warlock::getName() const
{
	return (_name);
}

std::string const	&Warlock::getTitle() const
{
	return (_title);
}

void	Warlock::setTitle(std::string const &str)
{
	_title = str;
}

void	Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}