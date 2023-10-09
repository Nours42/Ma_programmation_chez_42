/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/09 21:30:39 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class	Ice : public AMateria
{
	private:
		std::string _type;

	protected:

	public:
	
		Ice *clone() const;
		void use(ICharacter& target);
		std::string const & getType() const;

		////////////// canonical form ////////////////////
		Ice();											//
		~Ice();											//
		Ice(Ice const & ref);							//
		Ice & operator=(const Ice & ref);				//
		//////////////////////////////////////////////////
};

#endif