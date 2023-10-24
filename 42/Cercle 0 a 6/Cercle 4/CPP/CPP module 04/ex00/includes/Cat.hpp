/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 12:26:57 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

// ici pas besoin du virtual

class	Cat : public Animal
{
	private:
		
		std::string	type;

	public:

		std::string getType( void ) const;
		void makeSound( void ) const;

		// canonical form
		Cat();
		Cat(Cat & ref);
		~Cat();

		Cat & operator=(const Cat & rhs);
};

#endif