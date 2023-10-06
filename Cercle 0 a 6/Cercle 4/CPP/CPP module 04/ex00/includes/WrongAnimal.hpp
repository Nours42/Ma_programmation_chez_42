/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 07:35:10 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "Animal.hpp"

// le mot clef virtual fait que le programme choisit a l'execution 
// (et non pas a la compilation) ce au'il doit faire.

class	WrongAnimal
{
	private:
		
		std::string	type;

	public:

		virtual std::string getType( void ) const;
		virtual void makeSound( void ) const;

		// canonical form
		WrongAnimal();
		WrongAnimal(WrongAnimal & ref);
		virtual ~WrongAnimal();

		WrongAnimal & operator=(const WrongAnimal & rhs);
};

#endif