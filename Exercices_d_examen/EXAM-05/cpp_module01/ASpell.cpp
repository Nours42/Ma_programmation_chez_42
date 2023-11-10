/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 05:08:57 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/09 17:01:16 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string const &n, std::string const &e)
{
	this->_name = n;
	this->_effects = e;
}

ASpell::~ASpell() {}

ASpell::ASpell(ASpell const & ref)
{
	*this = ref;
}
ASpell & ASpell::operator=(ASpell const & ref)
{
	this->_name = ref.name;
	this->_effects = ref.effects;
	return (*this);
}

std::string	const	&ASpell::getName() const
{
	return (this->_name);
}

std::string	const	&ASpell::getEffects() const
{
	return (this->_effects);
}

void	ASpell::launch(ATarget const & atarget_ref) const
{
	atarget_ref.getHitBySpell(*this);
}
