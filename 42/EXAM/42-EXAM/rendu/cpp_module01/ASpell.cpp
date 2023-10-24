/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:31:51 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/24 15:42:23 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ASpell.hpp"

~ASpell()
{}

ASpell()
{}

ASpell(ASpell const &ref)
{
	this = ref;
}

ASpell &operator=(ASpell const &ref)
{
	this = ref;
}
		
//// setter ////

//// getter ////

std::string	&getName() const
{
	return (this->_name);
}

std::string	&getEffects() const
{
	return (this->_effects);
}

//// other ////

ASpell(std::string name, std::string effects)
{
	this->_name = name;
	this->_effects = effects;
}