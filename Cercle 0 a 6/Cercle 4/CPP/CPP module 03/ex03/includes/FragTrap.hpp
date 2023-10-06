/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 05:25:55 by sdestann         ###   ########.fr       */
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
		~FragTrap();
		FragTrap & operator=(const FragTrap & rhs);

		void	attack(std::string const & target);
		void	highFivesGuys( void );
};

#endif