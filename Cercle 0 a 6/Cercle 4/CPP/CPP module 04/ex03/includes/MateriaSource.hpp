/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nours42 <nours42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:59:41 by sdestann          #+#    #+#             */
/*   Updated: 2023/10/09 22:00:00 by nours42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_inventory[4];

	protected:

	public:
	
		void		learnMateria(AMateria *m);
		AMateria*	createMateria(std::string const & type);

		////////////// canonical form ////////////////////////////
		MateriaSource();										//
		~MateriaSource();										//
		MateriaSource(MateriaSource const & ref);				//
		MateriaSource & operator=(const MateriaSource & ref);	//
		//////////////////////////////////////////////////////////
};

#endif