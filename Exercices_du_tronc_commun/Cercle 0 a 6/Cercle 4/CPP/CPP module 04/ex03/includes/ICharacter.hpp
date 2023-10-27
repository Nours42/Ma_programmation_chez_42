/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/10 13:20:57 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
# include <iostream>
# include "AMateria.hpp"
# include "colors.h"

class AMateria;

class ICharacter
{

public:

	virtual	~ICharacter(void) {}
	virtual	std::string const & getName(void) const = 0;
	virtual	void equip(AMateria * m) = 0;
	virtual	void unequip(int idx) = 0;
	virtual	void use(int idx, ICharacter & target) = 0;

};

#endif