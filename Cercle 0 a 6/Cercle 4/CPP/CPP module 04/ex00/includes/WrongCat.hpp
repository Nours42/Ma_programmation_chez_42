/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 12:27:22 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "Animal.hpp"

// ici pas besoin du virtual

class	WrongCat : public WrongAnimal
{
	private:
		
		std::string	type;

	public:

		std::string getType( void ) const;
		void makeSound( void ) const;

		// canonical form
		WrongCat();
		WrongCat(WrongCat & ref);
		~WrongCat();

		WrongCat & operator=(const WrongCat & rhs);
};

#endif