/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:31:51 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/24 15:41:35 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ATarget.hpp"

~ATarget()
{}

ATarget()
{}

ATarget(ATarget const &ref)
{
	this = ref;
}

ATarget &operator=(ATarget const &ref)
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

ATarget(std::string name, std::string effects)
{
	this->_name = name;
	this->_effects = effects;
}