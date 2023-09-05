/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 05:35:58 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/03 05:52:09 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{

}

HumanA::~HumanA()
{

}

void	HumanA::attack( void ) const
{
	std::cout << this->_name << " attacks with his " << this->_weapon.get_type() << std::endl;
}