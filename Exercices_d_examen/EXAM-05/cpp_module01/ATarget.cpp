/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 05:08:57 by sdestann          #+#    #+#             */
/*   Updated: 2023/11/03 05:17:07 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string const &t)
{
	this->type = t;
}

ATarget::~ATarget() {}

ATarget::ATarget(ATarget const & ref)
{
	*this = ref;
}
ATarget & ATarget::operator=(ATarget const & ref)
{
	this->type = ref.type;
	return (*this);
}

std::string	const	&ATarget::getType() const
{
	return (this->type);
}

void	ATarget::getHitBySpell(ASpell const & aspell_ref) const
{
	std::cout << this->type << " has been " << aspell_ref.getEffects() << "!" << std::endl;
}
