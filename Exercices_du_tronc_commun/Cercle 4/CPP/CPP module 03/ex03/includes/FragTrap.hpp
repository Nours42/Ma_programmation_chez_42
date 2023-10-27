/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/09 19:53:40 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
		
		// canonical form
		FragTrap(std::string name);
		FragTrap(const FragTrap & src);
		virtual ~FragTrap();
		FragTrap & operator=(const FragTrap & rhs);

		void	attack(std::string const & target);
		void	highFivesGuys( void );
};

#endif