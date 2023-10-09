/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/09 22:35:24 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class	ICharacter;

class	AMateria
{
	protected:
		
		const std::string	_type;

	public:
		////////////// canonical form ////////////////////
		AMateria();										//
		virtual ~AMateria();							//
		AMateria(AMateria const & ref);					//
		// AMateria & operator=(const AMateria & ref);	//
		//////////////////////////////////////////////////

		AMateria(std::string const & type);
		virtual std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		
};

#endif