/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/09 21:18:25 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class	Cure : public AMateria
{
	private:
		std::string _type;

	protected:

	public:
	
		Cure *clone() const;
		void use(ICharacter& target);
		std::string const & getType() const;

		////////////// canonical form ////////////////////
		Cure();											//
		~Cure();										//
		Cure(Cure const & ref);							//
		Cure & operator=(const Cure & ref);				//
		//////////////////////////////////////////////////
};

#endif