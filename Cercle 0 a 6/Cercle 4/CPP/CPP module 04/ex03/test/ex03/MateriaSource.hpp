/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:32:44 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/20 07:00:19 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include "colors.h"

class MateriaSource : virtual public IMateriaSource
{

public:

	MateriaSource(void);
	MateriaSource(MateriaSource const & input);
	MateriaSource const & operator=(MateriaSource const & input);
	~MateriaSource(void);

	void learnMateria(AMateria * m);
	AMateria * createMateria(std::string const & type);

private:

	AMateria * _slot[4];

};

#endif