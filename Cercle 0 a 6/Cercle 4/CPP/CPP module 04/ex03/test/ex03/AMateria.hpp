/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:52:57 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/19 22:55:04 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"
# include "colors.h"

class ICharacter;

class AMateria
{

protected:

	std::string	_type;

public:


	AMateria(std::string const & type);
	AMateria(AMateria const & input);
	AMateria const & operator=(AMateria const & input);
	virtual ~AMateria(void);

	std::string const & getType(void) const;

	virtual	AMateria *	clone(void) const = 0;
	virtual void		use(ICharacter & target);

private:
	
	AMateria(void);
	
};

#endif