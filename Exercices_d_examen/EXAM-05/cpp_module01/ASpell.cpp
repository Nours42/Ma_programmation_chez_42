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
	this->name = n;
	this->effects = e;
}

ASpell::~ASpell() {}

ASpell::ASpell(ASpell const & ref)
{
	*this = ref;
}
ASpell & ASpell::operator=(ASpell const & ref)
{
	this->name = ref.name;
	this->effects = ref.effects;
	return (*this);
}

std::string	const	&ASpell::getName() const
{
	return (this->name);
}

std::string	const	&ASpell::getEffects() const
{
	return (this->effects);
}

void	ASpell::launch(ATarget const & atarget_ref) const
{
	atarget_ref.getHitBySpell(*this);
}
