/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 12:27:06 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

// ici pas besoin du virtual

class	Dog : public Animal
{
	private:
		
		std::string	type;

	public:

		std::string getType( void ) const;
		void makeSound( void ) const;

		// canonical form
		Dog();
		Dog(Dog & ref);
		~Dog();

		Dog & operator=(const Dog & rhs);
};

#endif