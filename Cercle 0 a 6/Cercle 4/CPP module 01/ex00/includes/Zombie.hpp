/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:16:26 by sdestann          #+#    #+#             */
/*   Updated: 2023/09/02 17:46:13 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		const std::string	_name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce( void );
};

void randomChump( std::string name );
Zombie*	newZombie( std::string name );

#endif