/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/10 14:07:43 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{

protected:


public:

	Ice(void);
	Ice(std::string const & type);
	Ice(Ice const & input);
	Ice const & operator=(Ice const & input);
	~Ice(void);

	std::string const & getType(void) const;

	AMateria *	clone(void) const;
	void		use(ICharacter & target);

};

#endif