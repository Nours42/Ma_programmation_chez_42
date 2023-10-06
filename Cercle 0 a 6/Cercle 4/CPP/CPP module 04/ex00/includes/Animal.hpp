/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 07:35:10 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

// le mot clef virtual fait que le programme choisit a l'execution 
// (et non pas a la compilation) ce au'il doit faire.

class	Animal
{
	protected:
		
		std::string	type;

	public:

		virtual std::string getType( void ) const;
		virtual void makeSound( void ) const;

		// canonical form
		Animal();
		Animal(Animal & ref);
		virtual ~Animal();

		Animal & operator=(const Animal & rhs);
};

#endif