/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:04:23 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/19 22:28:57 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>
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