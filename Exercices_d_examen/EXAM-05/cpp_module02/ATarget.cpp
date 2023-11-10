/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:53:06 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/09 16:04:33 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string const &type)
{
	this->type = type;
}

ATarget::~ATarget() {}

ATarget::ATarget(ATarget const &ref)
{
	*this = ref;
}

ATarget &ATarget::operator=(ATarget const &ref)
{
	this->type = ref.type;
	return (*this);
}

std::string	const &ATarget::getType() const
{
	return (this->type);
}

void	ATarget::getHitBySpell(ASpell const &refAspell) const
{
	std::cout << this->type << " has been " << refAspell.getEffects() << "!" << std::endl;
}