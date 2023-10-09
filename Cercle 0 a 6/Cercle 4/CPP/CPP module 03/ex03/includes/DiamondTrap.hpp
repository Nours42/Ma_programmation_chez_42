/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/09 19:54:42 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:

		std::string	_name;
		
	public:
		
		using FragTrap::_hitpoints;
		using FragTrap::_attack_damage;
		using ScavTrap::_energy_points;
		using ScavTrap::attack;

		void	WhoAmI( void );
		
		// canonical form
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap & src);
		~DiamondTrap();
		DiamondTrap & operator=(const DiamondTrap & rhs);
};

#endif