/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/10 13:45:56 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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