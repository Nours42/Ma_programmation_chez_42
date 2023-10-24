/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/10 13:45:37 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "ICharacter.hpp"
# include "colors.h"

class ICharacter;

class AMateria
{

	private:
		
		AMateria(void);
	
	protected:

		std::string	_type;

	public:

		////////////// Norme /////////////////////////////////
		AMateria(std::string const & type);					//
		AMateria(AMateria const & input);					//
		AMateria const & operator=(AMateria const & input);	//
		virtual ~AMateria(void);							//
		//////////////////////////////////////////////////////

		std::string const & getType(void) const;

		virtual	AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter & target);
	
};

#endif