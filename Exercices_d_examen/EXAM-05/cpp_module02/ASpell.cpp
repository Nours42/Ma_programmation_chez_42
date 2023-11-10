/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:53:06 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/10 11:39:56 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string const &name, std::string const &effects)
{
	this->_name = name;
	this->_effects = effects;
}

ASpell::~ASpell(){}

ASpell::ASpell(ASpell const &ref)
{
	*this = ref;
}
ASpell &ASpell::operator=(ASpell const &ref)
{
	this->_name = ref._name;
	this->_effects = ref._effects;
	return (*this);
}

std::string	const &ASpell::getName(void) const
{
	return (this->_name);
}

std::string const &ASpell::getEffects(void) const
{
	return (this->_effects);
}

void ASpell::launch(ATarget const &refAtarget) const
{
	refAtarget.getHitBySpell(*this);
}