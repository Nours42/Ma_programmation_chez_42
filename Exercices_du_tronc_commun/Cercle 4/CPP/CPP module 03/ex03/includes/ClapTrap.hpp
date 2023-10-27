/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/09 19:59:54 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class	ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitpoints;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
		std::string		_class_name;
		unsigned int	_class_attack_energy_cost;
		
	private:
		static const unsigned int	_class_hp;
		static const unsigned int	_class_energy_points;
		static const unsigned int	_class_attack_damage;

	public:
		void			set_name(std::string name);
		void			set_hitpoints(unsigned int hitpoints);
		void			set_energy_points(unsigned int energy_points);
		void			set_attack_damage(unsigned int attack_damage);

		std::string		get_name( void ) const;
		unsigned int	get_hitpoints( void ) const;
		unsigned int	get_energy_points( void ) const;
		unsigned int	get_attack_damage( void ) const;

		std::string				get_class_name( void );
		static unsigned int		get_class_hp( void );
		static unsigned int		get_class_energy_points( void );
		static unsigned int		get_class_attack_damage( void );
		unsigned int			get_class_attack_energy_cost( void );

		void			attack(std::string const & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		// canonical form
		ClapTrap(std::string name);
		ClapTrap(std::string name, std::string class_name);
		ClapTrap(std::string name, std::string class_name, unsigned int hp, unsigned energy_points, unsigned int attack_damage);
		ClapTrap(const ClapTrap & src);
		virtual ~ClapTrap();

		ClapTrap & operator=(const ClapTrap & rhs);
};

#endif