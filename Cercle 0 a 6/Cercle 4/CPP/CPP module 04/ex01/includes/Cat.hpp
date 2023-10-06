/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/06 08:02:55 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

// ici pas besoin du virtual

class	Cat : public Animal
{
	private:
		
		std::string	type;
		Brain		*brain;

	public:

		std::string	getType( void ) const;
		void		makeSound( void ) const;
		Brain		*getBrain( void ) const;

		// canonical form
		Cat();
		~Cat();
		Cat(Cat & ref);
		Cat & operator=(const Cat & rhs);
};

#endif