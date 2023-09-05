/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:15:39 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/02 18:19:41 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{

}

void	Zombie::set_name(std::string new_name)
{
	this->_name = new_name;
}

Zombie::Zombie(std::string name) : _name(name)
{
	announce();
}

Zombie::~Zombie()
{
	std::cout << "this Zombie named " << this->_name << " is really dead ... for now." << std::endl;
}