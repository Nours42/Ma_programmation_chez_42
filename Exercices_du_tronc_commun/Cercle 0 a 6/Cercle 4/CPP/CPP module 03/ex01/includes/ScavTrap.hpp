/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/05 14:57:14 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	private:
		static const unsigned int	_class_hp;
		static const unsigned int	_class_energy_points;
		static const unsigned int	_class_attack_damage;
		static const unsigned int	_class_attack_energy_cost;

	public:
		
		// canonical form
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap & src);
		~ScavTrap();
		ScavTrap & operator=(const ScavTrap & rhs);

		void	guardGate( void );
		void	attack(std::string const & target);
};

#endif