/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:02:29 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/19 22:52:43 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
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