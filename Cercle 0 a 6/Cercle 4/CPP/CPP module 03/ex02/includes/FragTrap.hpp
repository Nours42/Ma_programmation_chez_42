/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/05 15:31:27 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	private:
		static const unsigned int	_class_hp;
		static const unsigned int	_class_energy_points;
		static const unsigned int	_class_attack_damage;
		static const unsigned int	_class_attack_energy_cost;

	public:
		
		// canonical form
		FragTrap(std::string name);
		FragTrap(const FragTrap & src);
		~FragTrap();
		FragTrap & operator=(const FragTrap & rhs);

		void	guardGate( void );
		void	attack(std::string const & target);
		void	highFivesGuys( void );
};

#endif