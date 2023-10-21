/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:58:58 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/19 22:28:52 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{

protected:


public:

	Cure(void);
	Cure(std::string const & type);
	Cure(Cure const & input);
	Cure const & operator=(Cure const & input);
	~Cure(void);

	std::string const & getType(void) const;

	AMateria *	clone(void) const;
	void		use(ICharacter & target);

};

#endif